#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#include <float.h>
#include <time.h>

int* array_steps(int num, int start, int step)
{
	int* arr = (int*)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		arr[i] = start + (i * step);
	}
	return arr;
}

int* num_to_array(int n)
{
	int size = (int)log10(abs(n)) + 1;
	int* arr = (int*)calloc(size+1, sizeof(int));
	for (int i = 0; i < size;i++)
	{
		arr[i] = n % 10;
		n /= 10;
	}
	arr[size] = -1;
	return arr;
}

char* string_without_spaces(char x[])
{
	int letters = 0, i=0;
	while (x[i] != '\0')
	{
		if (x[i] != ' ') letters++;
		i++;
	}
	char* p = calloc(letters+1, 1);
	for (int k = 0, j = 0; k < i; k++)
	{
		if (x[k] != ' ')
		{
			p[j] = x[k];
			j++;
		}
	}
	p[letters] = '\0';
	return p;
}

char* concatenate_strings(char x[], char y[])
{
	int i = 0, j = 0;
	while (x[i] != '\0')
	{
		i++;
	}
	while (y[j] != '\0')
	{
		j++;
	}
	char* p = calloc(i + j + 1, 1);
	for (int k = 0; k < i; k++)
	{
		p[k] = x[k];
	}
	for (int l = 0; l < j; l++)
	{
		p[l+i] = y[l];
	}
	p[i + j] = '\0';
	return p;
}

//typedef struct
//{
//	double Re, Im;
//} CMPLX;
//
//typedef struct
//{
//	int num;
//	CMPLX* arr;
//} CMPLX_SET;
//
//void create_random_set(CMPLX_SET* pcs, int num)
//{
//	pcs->num = num;
//	pcs->arr = calloc(pcs->num, sizeof(double) * 2);
//	for (int i = 0; i < pcs->num; i++)
//	{
//		pcs->arr[i].Re = rand() % 100;
//		pcs->arr[i].Im = rand() % 100;
//		printf("%lf", pcs->arr[i].Im);
//	}
//}

void Set6(int chosenTask)
{
	switch (chosenTask)
	{
	case 1:
		int x1;
		printf("\nPut size of array: ");
		if (scanf("%d", &x1) == 1)
		{
			double *p = (double*) calloc(x1, sizeof(double));
			for (int i = 0; i < x1; i++)
			{
				printf("\nPut number: ");
				scanf("%lf", &p[i]);
			}
			double sum1 = 0;
			for (int i = 0; i < x1; i++)
			{
				sum1 += p[i];
			}
			printf("Sum is equal: %lf", sum1);
			free(p);
		}
		break;
	case 2:
		int x2, y2, z2;
		printf("\nPut size of array, first number and step");
		if (scanf("%d %d %d", &x2, &y2, &z2) == 3)
		{
			int* i2 = array_steps(x2, y2, z2);
			for (int i = 0; i < x2; i++)
			{
				printf("\n%d", i2[i]);
			}
			free(i2);
		}
		break;
	case 3:
		int x3, y3 = 0;
		printf("\nPut a integer: ");
		if (scanf("%d", &x3) == 1)
		{
			int* i3 = num_to_array(x3);
			while (i3[y3] != -1)
			{
				printf("%d  ", i3[y3]);
				y3++;
			}
			free(i3);
		}	
		break;
	case 4:
		char x4[] = "I'm blue da ba dee";
		char* y4 = string_without_spaces(x4);
		printf("\n%s",x4);
		printf("\n%s", y4);
		free(y4);
		break;
	case 5:
		char x5[] = "I'm blue ", y5[] = "da ba dee";
		printf("\n%s", x5);
		printf("\n%s", y5);
		char* z5 = concatenate_strings(x5, y5);
		printf("\n\n%s", z5);
		free(z5);
		break;
	/*case 6:
		CMPLX_SET b;
		CMPLX_SET* a = &b;
		create_random_set(a, 3);
		printf("%lf", a->arr[1].Im);
		break;*/
	default:
		printf("There is no such Task!");
		break;
	}
}