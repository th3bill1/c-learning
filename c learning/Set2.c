#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

double power1(double x, int y)
{
	double a = 1;
	for (int i = 0; i < y; i++)
	{
		a *= x;
	}
	return a;
}

double power2(double x, int y)
{
	if (y > 0) return power2(x, y - 1) * x;
	return 1;
}

_Bool IsPrime(int x)
{
	if (x <= 1) return 0;
	if (x == 2) return 1;
	for (int i = 2; i <= (int)(sqrt(x)); i++)
	{
		if (x % i == 0) return 0;
	}
	return 1;
}

double mean(double data[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += data[i];
	}
	return sum / size;

}

double standard_deviation(double data[], int size)
{
	double sumOfSquares = 0;
	for (int i = 0; i < size; i++)
	{
		sumOfSquares += power2(data[i]-mean(data, size), 2);
	}
	return sqrt(sumOfSquares / size);
}

double calculate(double a, double b, char s)
{
	if (s == '+') return a + b;
	if (s == '-') return a - b;
	if (s == '*') return a * b;
	if (s == '/' && b!=0) return a / b;
	return 0;
}

int IsArmstrong(int n)
{
	if (n == 0 || n == 1) return 1;
	if (n < 100) return 0;
	int sum = 0, temp, numOfDig = (int)log10(n)+1, m = n;
	while (n > 0)
	{
		temp = n % 10;
		sum += (int)power2(temp,numOfDig);
		n /= 10;
	}
	if (sum==m) return 1;
	else return 0;
}

void Set2(int chosenTask)
{
	switch (chosenTask)
	{
	case 1:
		double x1;
		int y1;
		printf("Put number (double) and power (int):\n");
		if (scanf("%lf %d", &x1, &y1) == 2)
		{
			printf("%lf", power1(x1, y1));
		}
		break;
	case 2:
		double x2;
		int y2;
		printf("Put number (double) and power (int):\n");
		if (scanf("%lf %d", &x2, &y2) == 2)
		{
			printf("%lf", power1(x2, y2));
		}
		break;
	case 3:
		int x3, y3, z3;
		printf("Put number: ");
		if (scanf("%d", &x3) == 1)
		{
			if (IsPrime(x3) == 1) printf("This number is prime.");
			if (IsPrime(x3) == 0) printf("This number is not a prime.");
		}
		printf("\nPut two numbers: \n");
		if (scanf("%d %d", &y3, &z3) == 2)
		{
			printf("Prime numbers between %d and %d:", y3, z3);
			for (int i = y3; i <= z3; i++)
			{
				if (IsPrime(i)) printf("\n %d", i);
			}
		}
		break;
	case 4:
		double x4, y4;
		char z4;
		printf("Put numbers and operator: \n");
		if (scanf("%lf %lf %c", &x4, &y4, &z4) == 3)
		{
			if (z4 == '/' && y4 == 0) printf("You cannot divide by 0!");
			else printf("Result is equal to: %lf", calculate(x4, y4, z4));
		}
		break;
	case 5:
		int x5;
		printf("Put number: ");
		if (scanf("%d", &x5) == 1)
		{
			if (IsArmstrong(x5) == 1) printf("This number is a Armstrong's number.");
			else printf("This number is not a Armstrong's number.");
		}
		break;
	case 6:
		double data6[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		int size6 = (sizeof(data6) / sizeof(data6[0]));
		printf("\nMean: %lf", mean(data6, size6));
		break;
	case 7:
		double data7[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		int size7 = (sizeof(data7) / sizeof(data7[0]));
		printf("\nStandard deviation: %lf\n", standard_deviation(data7, size7));
		break;
	default:
		printf("There is no such Task!");
		break;
	}

}
