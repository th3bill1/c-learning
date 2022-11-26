#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef enum Status
{
	avaliable,
	borrowed
}status;



typedef struct Book
{
	char title[80];
	int year;
	status status;
}book;

void printBook(book*);
int readBook(book*);
void copyBook(book*, book*);
int compareBooks(book*, book*);
void print_comparison(int);
void sortBooks(book[], int);
void print_book_arr(book[], int);

void Lab8() {
	puts("**************** Part 1 ****************");

	book a;
	readBook(&a);
	printBook(&a);


	puts("\n\n**************** Part 2 ****************");

	book b;
	puts("Copy Book (a to b)");
	copyBook(&b, &a);
	printBook(&b);


	puts("\n\n**************** Part 3 ****************");

	readBook(&b);

	puts("\nComparing Books:");

	printBook(&a);
	printf("\n");
	printBook(&b);
	printf("\nComparing a & b: %d; b & a: %d; b & b: %d", compareBooks(&a, &b), compareBooks(&b, &a), compareBooks(&b, &b));

	puts("\n\n**************** Part 4 ****************");

	book list[] = {
			{ "The Lord of the Rings", 1955, 1 },
			{ "Tristes Tropiques", 1955, 1 },
			{ "The Great Gatsby", 1925, 1 },
			{ "Waiting for Godot", 1952, 0 },
			{ "Midnight's Children", 1981, 0 },
			{ "1984", 1949, 0 },
			{ "For Whom the Bell Tolls", 1940,1 },
			{ "Il nome della rosa", 1981, 0 }
	};
	int const size = sizeof(list) / sizeof(book);
	puts("Unsorted list:");
	//Print the array list
	print_book_arr(list, size);
	//Sort it using sortBooks

	puts("\nSorted list:");
	sortBooks(list, size);
	print_book_arr(list, size);
	//Print the array again
}

int readBook(book* a)
{
	printf("Input: title year here|out\n");
	char b[5] = "here";
	scanf("%s %d %s",&a->title,&a->year, &b);
	if (!strcmp(b,"out")) a->status = borrowed;
	if (!strcmp(b,"here")) a->status = avaliable;
	return 0;
}

void printBook(book* a)
{
	printf("%s\t", a->title);
	const char* b = a->title;
	if (strlen(b) < 12) printf("\t\t");
	printf("%d ", a->year);
	if (a->status == borrowed) printf("borrowed");
	else printf("avaliable");
}

void copyBook(book* to, book* from)
{
	strcpy(to->title, from->title);
	to->year = from->year;
	to->status = from->status;
}

int compareBooks(book* a, book* b)
{
	if (a->status > b->status) return -1;
	else if (a->status < b->status) return 1;
	else
	{
		if (a->year > b->year) return 1;
		else if (a->year > b->year) return -1;
		else
		{
			int i = 0;
			while (a->title[i] != '\0')
			{
				if (b->title[i] == '\0') return 1;
				if (a->title[i] > b->title[i]) return 1;
				if (a->title[i] < b->title[i]) return -1;
				i++;
			}
			return 0;
		}
	}
}

void print_book_arr(book list[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		printBook(&list[i]);
	}
}

void sortBooks(book list[], int n)
{
	int k;
	book a;
	for (int i = 1; i < n; i++)
	{
		copyBook(&a, &list[i]);
		k = i - 1;
		while (compareBooks(&a, &list[k]) == -1 && k >= 0)
		{
			copyBook(&list[k + 1], &list[k]);
			k--;
		}
		copyBook(&list[k + 1], &a);
	}
}