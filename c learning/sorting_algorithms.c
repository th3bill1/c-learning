#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

void sa_print_array(int[], int);
void sa_selection_sort(int[], int);
void sa_insertion_sort(int[], int);
void sa_bubble_sort(int[], int);

void sortalg(void)
{
	int table[N] = { 3,7,1,25,5,2,4,7,4,90 };
	sa_print_array(table, N);
	sa_selection_sort(table, N);
	sa_insertion_sort(table, N);
	sa_bubble_sort(table, N);
}

void sa_print_array(int table[], int n)
{
	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("\n%d", table[i]);
	}
}

void sa_selection_sort(int table[], int n)
{
	for (int j = 0; j < n; j++)
	{
		int min = j;
		for (int i = j; i < n; i++)
		{
			if (table[i] < table[min])
			{
				min = i;
			}
		}
		int temp = table[j];
		table[j] = table[min];
		table[min] = temp;
	}
	sa_print_array(table, n);
}

void sa_insertion_sort(int table[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (table[j] < table[j + 1]) break;
			int temp = table[j];
			table[j] = table[i];
			table[i] = temp;
		}
	}
	sa_print_array(table, n);
}

void sa_bubble_sort(int table[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n - 1; j++)
		{
			if (table[j] > table[j + 1])
			{
				int temp = table[j];
				table[j] = table[j + 1];
				table[j + 1] = temp;
			}
		}
	}
	sa_print_array(table, n);
}