#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define N 5
#define K 10

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_cyclic(int* a, int* b, int* c)
{
	int temp = *a;
	*a = *c;
	*c = *b;
	*b = temp;
}
struct DigitAndHowMany
{
	int digit;
	int howMany;
};

struct DigitAndHowMany analyze_digits(int n)
{
	int size = ((int)log10(n) + 1), temp = 0, whichNum = 0;
	int howManyDigits[] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i <= size; i++)
	{
		howManyDigits[(n / ((int)pow(10, i))) % 10] += 1;
	}
	for (int i = 0; i <= size; i++)
	{
		if (howManyDigits[i] > temp)
		{ 
			temp = howManyDigits[i];
			whichNum = i;
		}
	}
	struct DigitAndHowMany a;
	a.howMany = temp;
	a.digit = whichNum;
	return  a;
}

void print_name_age(int ages[], char* names[])
{
	for (int i = 0; i < 5; i++)
	{
		if (ages[i] > 20 && names[i][0] == 'A') printf("%s\n", names[i]);
	}
}

void delete_element(char** words, int n)
{
	words[n] = NULL;
}

void array_print(char** words, int n)
{
	int j = 1;
	for (int i = 0; i < n; i++)
	{
		if (words[i] != NULL)
		{
			printf("\n%d.%s", j, words[i]);
			j++;
		}
	}
}

double weight_mean(double a[], double w[], int n)
{
	double sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		sum1 += a[i] * w[i];
		sum2 += w[i];
	}
	return sum1 / sum2;
}

struct minmax
{
	int min;
	int max;
};

struct minmax minumum_and_maximum(int arr[], int n)
{
	int min = INT_MAX, max = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}
	struct minmax x;
	x.min = min;
	x.max = max;
	return x;
}

void array_to_array_reversed(double arr1[], double arr2[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr2[i] = arr1[n - 1 - i];
	}
}

void Set3(int chosenTask)
{
	switch (chosenTask)
	{
	case 1:
		int x1, y1;
		printf("Put 2 numbers: ");
		if (scanf("%d %d", &x1, &y1) == 2)
		{
			printf("%d, %d \n", x1, y1);
			swap(&x1, &y1);
			printf("%d, %d \n", x1, y1);
		}
		break;
	case 2:
		int x2, y2, z2;
		printf("Put 2 numbers: ");
		if (scanf("%d %d %d", &x2, &y2, &z2) == 3)
		{
			int n2;
			printf("How many cycles: ");
			if (scanf("%d", &n2) == 1)
			{
				for (int i = 1; i <= n2; i++)
				{
					swap_cyclic(&x2,&y2,&z2);
					printf("%d, %d, %d \n", x2, y2, z2);
				}
			}
		}
	case 3:
		int x3;
		printf("Put a number: ");
		if (scanf("%d", &x3) == 1)
		{
			
			if (analyze_digits(x3).howMany > 1) printf("Number %d repeats in this number.", analyze_digits(x3).digit);
			else printf("There is no number repetition in this number.");
		}
		break;
	case 4:
		int x4;
		printf("Put a number: ");
		if (scanf("%d", &x4) == 1)
		{

			if (analyze_digits(x4).howMany> 1) printf("Number %d repeats in this number. %d times.", 
				analyze_digits(x4).digit, analyze_digits(x4).howMany);
			else printf("There is no number repetition in this number.");
		}
		break;
	case 5:
		int ages[] = { 43, 23, 21, 89, 2 };
		char* names[] = { "Alan", "Frank", "Ann", "John", "Andrew" };
		print_name_age(ages,names);
		break;
	case 6:
		char* words[] = {"Alan", "Frank", "Ann", "John", "Andrew"};
		int x6 = 5, y6;
		array_print(words, x6);
		printf("\nPut which to delete:");
		if (scanf("%d", &y6) == 1)
		{
			delete_element(words, y6);
		}
		array_print(words, x6); // Don't know how to make a reading function :(
		break;
	case 7:
		double arr81[N] = { 1.4, 6.7, 12.5, 14.2, 5.6 };
		double arr82[N] = { 5.5, 8.9, 11.2, 20.5, 3.2 };
		printf("Weighted mean: %lf", weight_mean(arr81,arr82,N));
		break;
	case 8:
		double arr91[N] = { 1.4, 6.7, 12.5, 14.2, 5.6 };
		double arr92[N];
		array_to_array_reversed(arr91, arr92, N);
		printf("array 1        array2");
		for (int i = 0; i < N; i++)
		{
			printf("\n%lf        %lf", arr91[i], arr92[i]);
		}
		break;
	case 9:
		int numbers[K] = { 12, 25, 45, 32, 15, 67, 9, 13, 23, 29 };
		struct minmax x9 = minumum_and_maximum(numbers, K);
		printf("Minimum: %d\nMaximum: %d", x9.min, x9.max);
		break;
	default:
		printf("There is no such Task!");
		break;
	}
}