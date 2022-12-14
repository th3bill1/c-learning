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
void Lab4(void);
void Lab5(void);
void Lab6(void);
void Lab7(void);
void Lab8(void);
void Lab9(void);
void Lab10(void);

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
	case 101:
		Lab1();
		break;
	case 102:
		Lab2();
		break;
	case 103:
		Lab3();
		break;
	case 104:
		Lab4();
		break;
	case 105:
		Lab5();
		break;
	case 106:
		Lab6();
		break;
	case 107:
		Lab7();
		break;
	case 108:
		Lab8();
		break;
	case 109:
		Lab9();
	case 110:
		Lab10();
		break;
	default: 
		printf("There is no such Set!");
		break;
	}
}