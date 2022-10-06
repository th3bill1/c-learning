#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

void TaskChoosing(int, int);

int main(void)
{
	int chosenSet, chosenTask;
	
	int programActive = 1;
	while (programActive)
	{
		printf("Put the number of Set you want to choose: ");
		if (scanf("%d", &chosenSet) == 1)
		{
			printf("Put the number of Task you want to choose :");
			if (scanf("%d", &chosenTask) == 1)
			{
				TaskChoosing(chosenSet, chosenTask);
			}
			else printf("Wrong input.");
		}
		else printf("Wrong input.");
	}
	return 0;
}