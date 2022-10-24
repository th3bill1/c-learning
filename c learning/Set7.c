#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#include <float.h>
#include <time.h>

struct slinked
{
	int value;
	struct slinked* next;
};

struct slinkedrep
{
	struct slinked* head;
	struct slinked* curr;
};

struct slinked* create_element()
{
	int x;
	printf("\n\nPut the value of element: ");
	if (scanf("%d", &x) == 1)
	{
		struct slinked* new_element = NULL;
		new_element = (struct slinked*)malloc(sizeof(struct slinked));
		new_element->value = x;
		return new_element;
	}
	return NULL;
}

void printel(struct slinked* x)
{
	printf("\n%d", x->value);
}

void printlist(struct slinked* x)
{
	while (x != NULL)
	{
		printf("\n%d", x->value);
		x = x->next;
	}
}

void insert_at_begining(struct slinked* head, struct slinked* target)
{
	target->next = head;
	head = target;
}

void destroy_list(struct slinked* head)
{
	while (head != NULL)
	{
		struct slinked* x = head;
		head = head->next;
		free(x);
	}
}

void Set7(int chosenTask)
{
	struct slinked* head = (struct slinked*)malloc(sizeof(struct slinked));
	struct slinked* second = (struct slinked*)malloc(sizeof(struct slinked));
	struct slinked* tail = (struct slinked*)malloc(sizeof(struct slinked));

	head->value = 1;
	head->next = second;
	second->value = 2;
	second->next = tail;
	tail->value = 5;
	tail->next = NULL;

	switch (chosenTask)
	{
	case 1:
		struct slinked* new_el1 = create_element();
		printel(new_el1);
		free(new_el1);
		break;
	case 2:
		printel(head);
		break;
	case 3:
		printlist(head);
		struct slinked* new_el3 = create_element();
		insert_at_begining(head, new_el3);
		printel(head);
		break;
	case 4:
		destroy_list(head);
		break;
	default:
		printf("There is no such Task!");
		break;
	}
	destroy_list(head);
}