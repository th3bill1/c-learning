#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double multiply(double, unsigned int);

double arrayProduct(unsigned int n, unsigned int A[]);

double arraySum(unsigned int n, unsigned int A[]);

_Bool IsLapYear(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return 1;
	else return 0;
}

double arraySum(unsigned int n, unsigned int A[])
{
	unsigned int sum = 0;
	for (unsigned int i = 0; i < n; i++)
	{
		sum += A[i];
	}
	return sum;
}

double multiply(double a, unsigned int b)
{
	double i;
	double r = 0;
	for (i = 0; i < b; i++)
	{
		r = r + a;
	}
	return r;
}

double arrayProduct(unsigned int n, unsigned int A[])
{
	double r = 1;
	unsigned int i = 0;
	while (i < n)
	{
		if (A[i] == 0)
			return -1; // Special value returned indicating that there was an element with value 0
		r = multiply(r, A[i]);
		i++;
	}


	return r;
}

void Lab2(void)
{
	int t;
	printf("Which task: ");
	scanf("%d", &t);
	switch (t)
	{
	case 1:
		int a, b;
		printf("Put your numbers here:\n");
		if (scanf("%d %d", &a, &b) == 2)
		{
			while (a != b)
			{
				if (a > b)
				{
					a -= b;
					continue;
				}
				b -= a;
			}
		}
		printf("%d", a);
		break;
	case 2:
		int k, c, n;
		printf("Put your number here:\n");
		if (scanf("%d", &n) == 1)
		{
			for (k = 1; k <= n; k++)
			{
				for (c = 1; c <= n - k; c++)
					printf(" ");

				for (c = 1; c <= 2 * k - 1; c++)
					printf("*");

				printf("\n");
			}

			for (k = 1; k <= n - 1; k++)
			{
				for (c = 1; c <= k; c++)
					printf(" ");

				for (c = 1; c <= 2 * (n - k) - 1; c++)
					printf("*");

				printf("\n");
			}
		}
		break;
	case 3:
		int l;
		printf("Put your year here:\n");
		if (scanf("%d", &l) == 1)
		{
			if (IsLapYear(l) == 1) printf("This year is a lap year!");
			else printf("This year is not a leap year!");
		}
		break;
	case 4:
		int N = 6;
		unsigned int A1[] = { 1, 2, 3, 4, 5, 6 };
		unsigned int A2[] = { 0, 1, 2, 3, 4, 5 };
		printf("Product of A1: %f\n", arrayProduct(N, A1));
		printf("and product of A2: %f\n", arrayProduct(N, A2));
		printf("and sum of A1: %f\n", arraySum(N, A1));
		system("pause");
		break;
	}
}