#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

void Set2(int chosenTask)
{
	switch (chosenTask)
	{
	case 1:
		printf("Successful!");
		break;
	default:
		printf("There is no such Task!");
		break;
	}

}