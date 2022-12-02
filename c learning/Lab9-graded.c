#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NAMELEN 32

typedef enum Action
{
	BUY,
	SELL,
	AVG
}Action;

typedef struct Currency {
	char name[NAMELEN];
	float exchange_rate;
	Action action;

}Money;

void printCurrency(Money*);

int readCurrency(Money*);

Money averageExchangeRate(Money*, Money*);

int compareCurrency(Money*, Money*);

void sortCurrency(Money[], int);

typedef enum Dangerousness
{
	WILD,
	MIX,
	PET
}dangerousness;

typedef struct Animal
{
	char name[NAMELEN];
	float weight;
	dangerousness danger;
}Creature;

//void printAnimal();

//int readAnimal();

//mixAnimals();

//int compareAnimals();

//void sortAnimals();

void version_a9();
void version_b9();

void Lab9(void)
{
	int choice;
	printf("\nChoose version ( A - 1  B - 2 ): ");
	if (scanf("%d", &choice) == 1)
	{
		switch (choice)
		{
		case 1:
			version_a9();
			break;
		case 2:
			version_b9();
			break;
		default:
			break;
		}
	}
}

void version_a9() {

	struct Currency  a, b;
	if (!readCurrency(&a))
	{
		puts("Invalid format!\n");
		return;
	}
	printCurrency(&a);
	putchar('\n');

	if (!readCurrency(&b))
	{
		puts("Invalid format!\n");
		return;
	}
	printCurrency(&b);
	putchar('\n');

	{
		puts("Test average currencies:");
		struct Currency test_a = { "USD", 5, 1 };
		struct Currency test_b = { "USD", 4, 0 };
		struct Currency test_c = averageExchangeRate(&test_a, &test_b);
		printCurrency(&test_c);
		putchar('\n');
		struct Currency test_d = { "AUD", 4, 0 };
		test_c = averageExchangeRate(&test_a, &test_d);
		printCurrency(&test_c);
		putchar('\n');
		putchar('\n');
	}

	puts("Test comparing currencies:");
	printCurrency(&a);
	puts("\nand");
	printCurrency(&b);
	printf("\nResult (a&b)%d (b&a)%d (b&b)%d\n", compareCurrency(&a, &b), compareCurrency(&b, &a), compareCurrency(&b, &b));

	struct Currency list[] = {
		{ "Polish Zloty", 1.f, 0 },
		{ "United States dollar", 4.2f, 1 },
		{ "Euro", 4.4f, 0 },
		{ "Turkish Lira", 2.f, 1 },
		{ "Japanese Yen",2.3f ,0 },
		{ "Swedish krona",2.0f,1 },
		{ "Swiss frank",2.4f,0 },
		{ "Singapore dollar",2.2f,0 },
		{ "Euro", 4.f, 1 },
		{ "Swedish krona",2.5f,0 },
		{ "Swiss frank",2.2f,1 },
		{ "Singapore dollar",2.8f,1 },
		{ "Singapore dollar",2.4f,1 },
		{ "Polish Zloty", 1.1f, 1 }
	};

	const int size = sizeof(list) / sizeof(struct Currency);
	puts("\nUnsorted list");
	int i;
	for (i = 0; i < size; i++) {
		printCurrency(&list[i]);
		putchar('\n');
	}

	sortCurrency(list, size);

	puts("\nSorted list");
	for (i = 0; i < size; i++) {
		printCurrency(&list[i]);
		putchar('\n');
	}
}

void version_b9()
{
	//Part 1
	/*
	struct Animal  a, b;
	if (!readAnimal(&a))
	{
		puts("Invalid format!");
		return 0;
	}
	printAnimal(&a);
	putchar('\n');
	if (!readAnimal(&b))
	{
		puts("Invalid format!");
		return 0;
	}
	printAnimal(&b);
	putchar('\n');
	*/

	//Part 2
	/*
	{
		puts("\nTest animals mixing");
		struct Animal test_a = { "Bat", 5, 0 };
		struct Animal test_b = { "Mouse", 14, 1 };
		struct Animal test_c = mixAnimals(&test_a, &test_b);
		printAnimal(&test_c);
		putchar('\n');
		struct Animal test_d = { "Bat", 8, 1 };
		test_c = mixAnimals(&test_a, &test_d);
		printAnimal(&test_c);
		putchar('\n');
	}
	*/

	//Part 3
	/*
	puts("\nTest comparing animals:");
	printAnimal(&b);
	puts("\nand");
	printAnimal(&a);
	printf("\nResult (a&b)%d (b&a)%d (b&b)%d\n", compareAnimals(&a, &b), compareAnimals(&b, &a), compareAnimals(&b, &b));
	*/

	//Part 4
	/*struct Animal list[] = {
		{ "Lion", 1, 2 },
		{ "Panda", 46, 0 },
		{ "Cat", 4, 2 },
		{ "Lion", 200, 0 },
		{ "Anaconda",23 ,2},
		{ "Eagle", 20, 0 },
		{ "Dog",24,2 },
		{ "Cat",12,2 },
		{ "Panda", 40, 0 },
		{ "Anaconda",25,2 },
		{ "Lion",220,0 },
		{ "Eagle",28,0 },
		{ "Cat",24,0 },
		{ "Dog", 11, 2 }
	};


	int size = sizeof(list) / sizeof(struct Animal);
	list[0] = mixAnimals(&list[0], &list[1]);
	puts("\nUnsorted list");
	int i;
	for (i = 0; i < size; i++) {
		printAnimal(&list[i]);
		putchar('\n');
	}

	sortAnimals(list, size);

	puts("\nSorted list");
	for (i = 0; i < size; i++) {
		printAnimal(&list[i]);
		putchar('\n');
	}
	*/
}

int readCurrency(Money* currency)
{
	printf("Give: currency_name exchange_rate buy/sell (0/1)\n");
	if (scanf(" %s %f %d", &currency->name, &currency->exchange_rate, &currency->action) == 3) return 1;
	else return 0;
}

void printCurrency(Money* currency)
{
	printf("%s %f", currency->name, currency->exchange_rate);
	if (currency->action == BUY) printf(" buy");
	else if (currency->action == SELL) printf(" sell");
	else printf(" average");
}

Money averageExchangeRate(Money* curr1, Money* curr2)
{
	if ((strcmp(curr1->name, curr2->name) != 0) || (curr1->action == curr2->action) || (curr1->action == AVG) || (curr2->action == AVG))
	{
		Money result = { "EMPTY",-1,AVG };
		return result;
	}
	Money avarage;
	strncpy(avarage.name, curr1->name, NAMELEN);
	avarage.exchange_rate = curr1->exchange_rate / curr2->exchange_rate;
	avarage.action = AVG;
	return avarage;
}

int compareCurrency(Money* curr1, Money* curr2)
{
	if (strcmp(curr1->name, curr2->name) != 0) return strcmp(curr1->name, curr2->name);
	else if (curr1->action > curr2->action) return 1;
	else if (curr1->action < curr2->action) return -1;
	else if (curr1->exchange_rate > curr2->exchange_rate) return 1;
	else if (curr1->exchange_rate < curr2->exchange_rate) return -1;
	else return 0;
}

void copyCurrency(Money* dest, Money* org)
{
	strcpy(dest->name, org->name);
	dest->exchange_rate = org->exchange_rate;
	dest->action = org->action;
}

void sortCurrency(Money list[], int n)
{
	int k;
	Money a;
	for (int i = 1; i < n; i++)
	{
		copyCurrency(&a, &list[i]);
		k = i - 1;
		while ((compareCurrency(&a, &list[k]) == -1) && k >= 0)
		{
			copyCurrency(&list[k + 1], &list[k]);
			k--;
		}
		copyCurrency(&list[k + 1], &a);
	}
}