#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#include <float.h>
#define K 5

struct Rational
{
	int numerator, denominator;
};

struct Rational rational(int a, int b)
{
	struct Rational x;
	x.numerator = a;
	x.denominator = b;

	return x;
}

void print_rational(struct Rational a)
{
	printf("Numerator: %d\nDenominator: %d", a.numerator, a.denominator);
}

void asign_rational(struct Rational* a)
{
	printf("\nPut numerator: ");
	if (scanf("%d", &a->numerator) == 1);
	printf("\nPut denominator: ");
	if (scanf("%d", &a->denominator) == 1);
}

struct Rational add_rational(struct Rational a, struct Rational b)
{
	struct Rational x;
	x.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	x.denominator = a.denominator * b.denominator;
	return x;
}

struct Rational subtract_rational(struct Rational a, struct Rational b)
{
	struct Rational x;
	x.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
	x.denominator = a.denominator * b.denominator;
	return x;
}

struct Rational multiply_rational(struct Rational a, struct Rational b)
{
	struct Rational x;
	x.numerator = a.numerator * b.numerator;
	x.denominator = a.denominator * b.denominator;
	return x;
}

struct Rational divide_rational(struct Rational a, struct Rational b)
{
	struct Rational x;
	x.numerator = a.numerator * b.denominator;
	x.denominator = a.denominator * b.numerator;
	return x;
}

double rational_as_double(struct Rational a)
{
	return (double)a.numerator / a.denominator;
}

int compare_rationals(struct Rational a, struct Rational b)
{
	if ((double)a.numerator / a.denominator > (double)b.numerator / b.denominator) return 1;
	else if ((double)a.numerator / a.denominator < (double)b.numerator / b.denominator) return -1;
	else return 0;
}

struct Student
{
	char first_name[10];
	char last_name[20];
	int semester;
};

int compare_students(struct Student a, struct Student b)
{
	for (int i = 0; i < 10; i++)
	{
		if (a.first_name[i] > b.first_name[i]) return 1;
		else if (a.first_name[i] < b.first_name[i]) return -1;
	}
	for (int i = 0; i < 10; i++)
	{
		if (a.last_name[i] > b.last_name[i]) return 1;
		else if (a.last_name[i] < b.last_name[i]) return -1;
	}
	if (a.semester > b.semester) return 1;
	else if (a.semester < b.semester) return -1;
	else return 0;
}

void bubble_sort_students(struct Student a[], int n)
{
	struct Student temp;
	do
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (compare_students(a[i], a[i + 1]) == 1)
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
		n--;
	} while (n > 1);
}

void print_students(struct Student a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nFirst name:\t%s\tLast name:\t%s\tSemester:\t%d",
			a[i].first_name, a[i].last_name, a[i].semester);
	}
}

struct Length
{
	int meters, cenntimeters;
};

void print_length(struct Length a)
{
	printf("%d meters and %d centimeters", a.meters, a.cenntimeters);
}

void compare_lengths(struct Length a, struct Length b)
{
	int i = 0;
	if (a.meters > b.meters) i = 1;
	else if (a.meters < b.meters) i = -1;
	else if (a.cenntimeters > b.cenntimeters) i = 1;
	else if (a.cenntimeters < b.cenntimeters) i = -1;
	
	if (i == 1)
	{
		print_length(a);
		printf(" is longer than ");
		print_length(b);
	}
	else if (i == -1)
	{
		print_length(b);
		printf(" is longer than ");
		print_length(a);
	}
	else
	{
		printf("Both lengths are equal ");
		print_length(a);
	}
}

struct Length sum_of_lengths(struct Length a, struct Length b)
{
	struct Length sum;
	sum.meters = a.meters + b.meters;
	sum.cenntimeters = a.cenntimeters + b.cenntimeters;
	if (sum.cenntimeters >= 99)
	{
		sum.meters += (sum.cenntimeters / 100);
		sum.cenntimeters -= (sum.cenntimeters / 100)*100;
	}
	return sum;
}
struct Length difference_of_lengths(struct Length a, struct Length b)
{
	struct Length difference;
	difference.meters = a.meters - b.meters;
	difference.cenntimeters = a.cenntimeters - b.cenntimeters;
	if (difference.cenntimeters < 0)
	{
		difference.meters -= 1;
		difference.cenntimeters += 100;
	}
	return difference;
}

struct Time
{
	int hours, minutes, seconds;
};

void subtract_times(struct Time *a, struct Time *b)
{
	a->seconds -= b->seconds;
	if (a->seconds < 0)
	{
		a->minutes -= 1;
		a->seconds += 60;
	}
	a->minutes -= b->minutes;
	if (a->minutes < 0)
	{
		a->hours -= 1;
		a->minutes += 60;
	}
	a->hours -= b->hours;
}

void Set5(int chosenTask)
{
	switch (chosenTask)
	{
	case 1:
		int a1, a2;
		printf("\nPut numerator and denominator: ");
		if (scanf("%d %d", &a1, &a2)==2)
		{
			struct Rational x1 = rational(a1, a2);
			struct Rational x2 = { 5,8 };
			print_rational(x1);
			asign_rational(&x1);
			printf("\n\nSum is equal: %lf\nNumerator of sum: %d\nDenominator of sum: %d",
				rational_as_double(add_rational(x1,x2)), add_rational(x1, x2).numerator, add_rational(x1, x2).denominator);
			printf("\n\nDifference is equal: %lf\nNumerator of difference: %d\nDenominator of difference: %d",
				rational_as_double(subtract_rational(x1, x2)), subtract_rational(x1, x2).numerator, subtract_rational(x1, x2).denominator);
			printf("\n\nProduct is equal: %lf\nNumerator of product: %d\nDenominator of product: %d",
				rational_as_double(multiply_rational(x1, x2)), multiply_rational(x1, x2).numerator, multiply_rational(x1, x2).denominator);
			printf("\n\nQuotient is equal: %lf\nNumerator of quotient: %d\nDenominator of quotient: %d",
				rational_as_double(divide_rational(x1, x2)), divide_rational(x1, x2).numerator, divide_rational(x1, x2).denominator);
			printf("\n\nNumber as double: %lf", rational_as_double(x1));
			if (compare_rationals(x1, x2) == 1) printf("\n\n%lf is bigger than %lf", rational_as_double(x1), rational_as_double(x2));
			else if (compare_rationals(x1, x2) == -1) printf("\n\n%lf is smaller than %lf", rational_as_double(x1), rational_as_double(x2));
			else printf("\n\n%lf is equal than %lf", rational_as_double(x1), rational_as_double(x2));
		}
		break;
	case 2:
		struct Student students[K] = 
		{ {"Joe", "Biden", 1} ,{"Barack", "Obama",2}, {"Joe", "Trump", 3},{"Barack", "Obama",3},{"George","Bush",5} };
		printf("\nBefore sorting:\n");
		print_students(students, K);
		bubble_sort_students(students, K);
		printf("\n\nAfter sorting:\n");
		print_students(students, K);
		break;
	case 3:
		struct Length x3 = { 3,27 }, y3 = {2,43};
		compare_lengths(x3, y3);
		printf("\n\nSum is equal: ");
		print_length(sum_of_lengths(x3, y3));
		printf("\n\nDifference is equal: ");
		print_length(difference_of_lengths(x3, y3));
		break;
	case 4:
		struct Time x4 = { 4,47,25 }, y4 = { 2,48,37 };
		subtract_times(&x4, &y4);
		printf("Difference: %d hours %d minutes %d seconds", x4.hours, x4.minutes, x4.seconds);
		break;
	default:
		printf("There is no such Task!");
		break;
	}
}