#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

void Set1(int);
void Set2(int);

void TaskChoosing(int chosenSet, int chosenTask)
{
	switch (chosenSet)
	{
	case 1:
	{
		Set1(chosenTask); 
		break;
	}
	case 2: 
	{
		Set2(chosenTask);
		break;
	}
	default: 
		printf("There is no such Set!");
		break;
	}
}