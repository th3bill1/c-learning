#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

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
	default:
		printf("There is no such Task!");
		break;
	}
}