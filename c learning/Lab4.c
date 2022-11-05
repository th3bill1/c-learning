#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 32

void print_arr(double arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n%lf", arr[i]);
	}
}

void read_arr(double arr[], int n)
{
	printf("\nPut %d values", n);
	for (int i = 0; i < n; i++)
	{
		scanf("\n%lf", &arr[i]);
	}
}

double norm(double arr[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i] * arr[i];
	}
	return sqrt(sum);
}

void print_norm(double arr[], int n)
{
	printf("\n\nNorm: %lf", norm(arr, n));
}

void sort_arrays(double* Z[], int n, int j)
{
	do
	{
		for (int i = 0; i < j - 1; i++)
		{
			if (norm(Z[i], n) < norm(Z[i + 1], n))
			{
				double* temp = Z[i];
				Z[i] = Z[i + 1];
				Z[i + 1] = temp;
			}
		}
		j--;
	} while (j > 1);
}

int is_symetric(double* arr[], int j)
{
	for (int i = 0; i < j; i++)
	{
		for (int k = 0; k < j; k++)
		{
			if (arr[i][k] != arr[k][i]) return 0;
		}
	}
	return 1;
}

int Lab4(void)
{
	double A[N], B[N], C[N];
	double* Z[] = { A, B, C };
	int n;
	printf("How big arr: ");
	if (scanf("%d", &n) == 1)
	{
		read_arr(A, n);
	}
	printf("Printed:");
	print_arr(A, n);
	print_norm(A, n);
	read_arr(B, n);
	print_norm(B, n);
	read_arr(C, n);
	print_norm(C, n);
	sort_arrays(Z, n, 3);
	for (int i = 0; i < 3; i++)
	{
		print_arr(Z[i], n);
		print_norm(Z[i], n);
	}
	if (is_symetric(Z, 3) == 1) printf("this matrix is symetric!");
	else printf("this matrix is not symetric!");


	return 0;
}