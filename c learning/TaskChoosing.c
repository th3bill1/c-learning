#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

void Set1(int);
void Set2(int);
void Set3(int);
void Set4(int);
void Lab1(void);
void Lab2(void);

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
	case 3: 
	{
		Set3(chosenTask);
		break;
	}
	case 4: 
	{
		Set4(chosenTask);
		break;
	}
	case 11:
		Lab1();
		break;
	case 12:
		Lab2();
		break;
	default: 
		printf("There is no such Set!");
		break;
	}
}