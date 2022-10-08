#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

void TaskChoosing(int, int);

int main(void)
{
	int chosenSet, chosenTask;

	while (1)
	{
		printf("\nPut the number of Set you want to choose (if you want to leave put 0), for labs put 1#, where # is the number of lab: ");
		if (scanf("%d", &chosenSet) == 1)
		{
			if (chosenSet == 0) break;
			if (chosenSet > 10) TaskChoosing(chosenSet, 0);
			else if (chosenSet < 11)
			{
				printf("Put the number of Task you want to choose :");
				if (scanf("%d", &chosenTask) == 1) TaskChoosing(chosenSet, chosenTask);
				else printf("Wrong input.");
			}
		}
		else printf("Wrong input.");
	}
	return 0;
}