#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void)
{
	int chosenSet, chosenTask;
	printf("Put the number of exercise set: ");
	if (scanf("%i", &chosenSet) == 1 && chosenSet > 0 && chosenSet < 9)
	{
		switch (chosenSet)
		{
		case 1:
			printf("Put the number of exercise: ");
			if (scanf("%i", &chosenTask) == 1 && chosenTask > 0 && chosenSet < 18)
			{
				switch (chosenTask)
				{
				case 1:
					double side, perimeter, area;
					printf("Put the side length of your square: ");
					if (scanf("%lf", &side) == 1)
					{
						if (side > 0)
						{
							perimeter = side * 4;
							printf("\nPerimeter equales: %lf", perimeter);
							area = side * side;
							printf("\nArea equales: %lf", area);
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
							printf("\nArea equales: %lf", area2);
							printf("\n");
						}
						else printf("Radius of the circle must be a positive number.");
					}
					break;
				}
			}
			else printf("There is no such task. There is 18 tasks avaliable.\n");
			break;
		case 2:
			break;
		}

	}
	else printf("There is no such set. There are 8 sets avaliable.");
	return 0;
}
