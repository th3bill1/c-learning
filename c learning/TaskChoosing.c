#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

void Set1(int);
void Set2(int);
void Set3(int);
void Set4(int);
void Set5(int);
void Set6(int);
void Set7(int);
void Lab1(void);
void Lab2(void);
void Lab3(void);

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
	case 5: 
	{
		Set5(chosenTask);
		break;
	}
	case 6: 
	{
		Set6(chosenTask);
		break;
	}
	case 7: 
	{
		Set7(chosenTask);
		break;
	}
	case 11:
		Lab1();
		break;
	case 12:
		Lab2();
		break;
	case 13:
		Lab3();
		break;
	default: 
		printf("There is no such Set!");
		break;
	}
}