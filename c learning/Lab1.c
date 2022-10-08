#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Lab1(void)
{
	double radius;
	double pi = acos(-1);
	printf("Put the radius of a circle: ");
	if (scanf("%lf", &radius) == 1)
	{
		if (radius > 0)
		{
			printf("Perimeter is equal to: %lf. Area is equal: %lf.\n", 2 * pi * radius, pi * radius * radius);
		}
		else printf("Radius must be positive number.");
	}
	else printf("Wrong input.");
	int n;
	printf("Put the number of points: ");
	if (scanf("%d", &n) == 1)
	{
		if (n > 0)
		{
			double angle = (2 * pi) / n;
			double x = radius, y = 0;
			for (int a = 1; a < n + 1; a++)
			{
				printf("[%lf, %lf]\n", x, y);
				x = radius * cos(angle * a);
				y = radius * sin(angle * a);
			}
		}
		else printf("Number must be positive.");
	}
	else printf("Wrong input.");
	double eps, areaCirc, areaPoly = 0, difference;
	int numberOfSides = 3;
	areaCirc = pi * radius * radius;
	difference = areaPoly - areaCirc;
	printf("Put precision: ");
	if (scanf("%lf", &eps) == 1)
	{
		while (fabs(difference) > eps)
		{
			areaPoly = radius * radius * numberOfSides * sin(2 * pi / numberOfSides) * 0.5;
			difference = areaPoly - areaCirc;
			numberOfSides++;
		}
		printf("%d-sided polygon with area %lf", numberOfSides - 1, areaPoly);
	}
}