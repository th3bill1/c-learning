#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

//Helper function used for various test ensuring correct implementation.
void check(int cond, const char* errmsg)
{
	if (!cond)
	{
		fprintf(stderr, "Check failed: %s!", errmsg);
		exit(EXIT_FAILURE);
	}
}

typedef struct Card
{
	unsigned char suit; // values 1-4 denote (in order) Spades, Clubs, Diamonds, Hearts
	unsigned char rank; // values 9-14 denote (in order): 9, 10, J, Q, K, A
} Card;

typedef struct DeckElem
{
	Card c;
	struct DeckElem* next, * prev;
} DeckElem;

typedef struct Deck
{
	DeckElem* head, * tail;
} Deck;

Card card_init(unsigned char s, unsigned char r)
{
	Card c;
	c.suit = s;
	c.rank = r;
	return c;
}

Card card_random()
{
	return card_init(rand() % 4 + 1, rand() % 6 + 9);
}

void card_print(Card c)
{
	check(c.suit > 0 && c.suit <= 4, "card_print - Invalid suit!");
	check(c.rank > 8 && c.rank <= 14, "card_print - Invalid rank");
	static const char suit_lookup[] = { 'S', 'C', 'D', 'H' };
	static const char rank_lookup[] = { 'J', 'Q', 'K', 'A' };
	putchar('[');
	if (c.rank > 10)
		putchar(rank_lookup[c.rank - 11]);
	else
		printf("%hhu", c.rank);
	putchar(suit_lookup[c.suit - 1]);
	putchar(']');
}

DeckElem* deck_create_elem(Card c);

void deck_append_elem(Deck* d, DeckElem* el);

void deck_print(const Deck* d);

void deck_destroy(Deck* d);

DeckElem* deck_unlink_last(Deck* d);

void deck_reverse(Deck* d);

void deck_prepend(Deck* dst, Deck* src);

Deck deck_build();

void deck_deal(Deck* d, Deck hands[], unsigned count);

#define MAX_HANDS 10
void deck_shuffle(Deck* d);

void Lab12(void)
{
	//For Part 1 remember to uncomment two additional lines between Parts 2 and 3
	
	puts("**********************Part 1**********************");
	Deck d = { NULL, NULL };
	int i;
	srand(9854);
	for (i = 0; i < 10; ++i)
	{
		DeckElem *tmp = deck_create_elem(card_random());
		deck_append_elem(&d, tmp);
	}
	deck_print(&d);

	puts("\n**********************Part 2**********************");
	for (i = 0; i < 4; ++i)
	{
		DeckElem *tmp = deck_unlink_last(&d);
		printf("Last: ");
		card_print(tmp->c);
		putchar('\n');
		free(tmp);
	}

	puts("Reversing the rest...");
	deck_reverse(&d);
	deck_print(&d);
	
	deck_destroy(&d);
	check(d.head == NULL && d.tail == NULL, "Deck should be empty");

	puts("\n**********************Part 3**********************");
	for (i = 0; i < 3; ++i)
	{
		Deck d2 = { NULL, NULL };
		int j = rand() % 10 + 1;
		while (j--)
		{
			DeckElem *tmp = deck_create_elem(card_random());
			deck_append_elem(&d2, tmp);
		}
		printf("d2: ");
		deck_print(&d2);
		puts("Prepending d2 to d");
		deck_prepend(&d, &d2);
		printf("d : ");
		deck_print(&d);
		check(d2.head == NULL && d2.tail == NULL, "Second deck should be empty");
	}
	deck_destroy(&d);

	puts("Building deck...");
	d = deck_build();
	deck_print(&d);

	puts("\n**********************Part 4**********************");
	puts("Dealing cards...");
	Deck hands[3] = { {NULL, NULL} };
	deck_deal(&d, hands, 3);
	for (i = 0; i < 3; ++i)
	{
		printf("Hand %d: ", i + 1);
		deck_print(hands + i);
		deck_destroy(hands + i);
	}
	check(d.head == NULL && d.tail == NULL, "First deck should be empty");

	puts("\n**********************Part 5**********************");
	d = deck_build();
	deck_print(&d);
	puts("Shuffling 10 times...");
	for (i = 0; i < 10; ++i)
		deck_shuffle(&d);
	deck_print(&d);
	deck_destroy(&d);
}

DeckElem* deck_create_elem(Card c)
{
	DeckElem* new_card = (DeckElem*)malloc(sizeof(DeckElem));
	if (&c)
	{
		new_card->c = c;
		new_card->next = NULL;
		new_card->prev = NULL;
		return new_card;
	}
	printf("error");
	return NULL;
}

void deck_append_elem(Deck* d, DeckElem* el)
{
	if (!d->head)
	{
		d->head = el;
		d->tail = el;
		return;
	}
	el->prev = d->tail;
	el->prev->next = el;
	d->tail = el;
	d->tail->next = NULL;
}

void deck_print(const Deck* d)
{
	DeckElem* temp = d->head;
	do
	{
		card_print(temp->c);
		temp = temp->next;
	} while (temp);
	printf("\n");
}

void deck_destroy(Deck* d)
{
	d->head = NULL;
	d->tail = NULL;
}

DeckElem* deck_unlink_last(Deck* d)
{
	if (!d->head->next) d->head = NULL;
	d->tail = d->tail->prev;
	DeckElem* temp = d->tail->next;
	d->tail->next = NULL;
	return temp;
}

void deck_reverse(Deck* d)
{
	d->head->prev = NULL;
	d->head = d->tail;
	DeckElem* temp = d->tail->prev;
	d->head->prev = NULL;
	DeckElem* temp2;
	while (temp)
	{
		temp2 = temp->prev;
		deck_append_elem(d,temp);
		temp = temp2;
	}
}

void deck_prepend(Deck* dst, Deck* src)
{
	src->tail->next = dst->head;
	dst->head = src->head;
	deck_destroy(src);
}

Deck deck_build()
{
	Deck d = { NULL, NULL };
	Card temp;
	DeckElem* temp2;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 6; i++)
		{

			temp = card_init((char)j+1,(char)i+9);
			temp2 = deck_create_elem(temp);
			deck_append_elem(&d,temp2);
		}
	}
	return d;
}

void deck_deal(Deck* d, Deck hands[], unsigned n)
{
	while (d->head)
	{
		for (unsigned i = 0; i < n; i++)
		{
			if (d->tail->prev&&d->head->next)
			{
				d->tail = d->tail->prev;
				deck_append_elem(&hands[i], d->tail->next);
				d->tail->next = NULL;
			}
			else
			{
				deck_append_elem(&hands[i], d->head);
				d->head = NULL;
				break;
			}

		}
	}
	deck_destroy(d);
}

void deck_shuffle(Deck* d)
{
	int i = rand()%9+2;
	Deck* decks = (Deck*)calloc(i, sizeof(Deck));

	deck_deal(d, decks, i);
	for (int k = 0; k < i-1; k++)
	{
		decks[k].tail->next = decks[k + 1].head;
		decks[k + 1].head->prev = decks[k].tail;
	}
	d->head = decks[0].head;
	d->tail = decks[i - 1].tail;
}