#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

void Set1(int chosenTask)
{
	switch (chosenTask)
	{
	case 1:
		double side, perimeter, area;
		printf("Put the side length of your square: ");
		if (scanf(" %lf", &side) == 1)
		{
			if (side > 0)
			{
				perimeter = side * 4;
				printf("\nPerimeter equales: %lf", perimeter);
				area = side * side;
				printf("\nArea equales: %lf\n", area);
				printf("\n");
			}
			else printf("Side length must be a positive number.");
		}
		else printf("Wrong input!");
		break;
	case 2:
		double radius, perimeter2, area2;
		printf("Put the radius of your circle: ");
		if (scanf("%lf", &radius) == 1)
		{
			if (radius > 0)
			{
				perimeter2 = 2 * radius * M_PI;
				printf("\nPerimeter equales: %lf", perimeter2);
				area2 = radius * radius * M_PI;
				printf("\nArea equales: %lf\n", area2);
			}
			else printf("Radius of the circle must be a positive number.");
		}
		break;
	case 3:
		int integer1, integer2, quotient, reminder;
		double doubleQuotient;
		printf("Put the two numbers you want to divide: \n");
		if (scanf("%d%d", &integer1, &integer2) == 2)
		{
			if (integer2 != 0)
			{
				quotient = integer1 / integer2;
				reminder = integer1 - quotient * integer2;
				doubleQuotient = (double)integer1 / integer2;
				printf("Quotient is equal to %lf\n", doubleQuotient);
				printf("Reminder is equal to %d\n", reminder);
			}
			else printf("You cannot divide by 0");
		}
		else printf("Wrong input.");
		break;
	case 4:
		const int temperature = 27;
		double temperature2;
		temperature2 = (double)(temperature - 32) / 1.8;
		printf("Temperature = %lf", temperature2);
		break;
	case 5:
		const double conv = 1.61;
		double kilometers, miles;
		printf("Put the distance in kilometers: ");
		if (scanf("%lf", &kilometers) == 1)
		{
			if (kilometers > 0)
			{
				miles = kilometers / conv;
				printf("%lf kilometers is equal to %lf miles.\n", kilometers, miles);
			}
			else printf("Distance must be a positive number.");
		}
		else printf("Wrong input.");
		break;
	case 6:
		int number;
		printf("Put your number: ");
		if (scanf("%d", &number) == 1)
		{
			if (number % 2 == 1) printf("This number is odd\n");
			else printf("This number is even\n");
		}
		else printf("Input must be an integer.");
		break;
	case 7:
		char character;
		printf("Put the character which ASCII Value you want to see: ");
		if (scanf(" %c", &character) != 0)
		{
			printf("ASCII Value of %c is %d\n", character, character);
		}
		break;
	case 8:
		char character2;
		printf("Put the character: ");
		if (scanf(" %c", &character2) == 1)
		{
			if ((int)(character2) > 64 && (int)(character2) < 91)
			{
				printf("This character is a letter\n");
			}
			else if ((int)(character2) > 96 && (int)(character2) < 123)
			{
				printf("This character is a letter\n");
			}
			else
			{
				printf("This character is not a letter.\n");
			}
		}
		break;
	case 9:
		double a, b, c;
		printf("Put the lengths of line segments: \n");
		if (scanf("%lf%lf%lf", &a, &b, &c) == 3)
		{
			if (a + b > c && a + c > b && b + c > a)
			{
				printf("Triangle can be constructed form those line segments.\n");
			}
			else printf("Triangle cannot be constructed form those line segments.\n");
		}
		break;
	case 10:
		double weight, height,bmi;
		printf("Put weight (in kg) and height (in cm): \n");
		if (scanf("%lf%lf", &weight, &height) == 2)
		{
			bmi = (weight / (height * height)) * 10000;
			if (bmi <= 18.5) printf("Underweight\n");
			else if (bmi > 18.5 && bmi <= 25) printf("Normal weight\n");
			else if (bmi > 25 && bmi <= 30) printf("Underweight\n");
			else printf("Obesity\n");
		}
		else printf("Wrong input.");
		break;
	default:
		printf("There is no such Task!");
		break;
	}
}