#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10

int Lab3(void)
{
    int q[] = { 2, 5, 10 };
    printf("a_N\tq = %d\tq = %d\tq = %d", q[0], q[1], q[2]);
    for (int i = 0; i < 11; i++)
    {
        printf("\n%d\t%d\t%d\t%d", i, q[0] * i + 1, q[1] * i + 1, q[2] * i + 1);
    }
    int secret[SIZE] = { 23, 45, 87, 130, 78, 92, 11, 39, 99, 200 };
    int temp = 1, min = INT_MAX;
    printf("\nEnter sequence of positive integers (first non-positive number ends sequence):");
    while (temp > 0)
    {
        if (scanf("%d", &temp) == 1)
        {
            if (temp < min)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    if (secret[i] == temp) min = temp;
                }
            }
        }
    }
    printf("\nSmallest value found in secret integers is equal %d", min);
    int size = 1;
    printf("\nEnter the size of N:");
    if (scanf("%d", &size) == 1)
    {
        for (int i = 0; i < size; i++)
        {
            printf("\n|");
            for (int j = 0; j < i; j++)
            {
                printf(" ");
            }
            printf("\\");
            for (int k = 0; k < size - i - 1; k++)
            {
                printf(" ");
            }
            printf("|");
        }
    }
    return 0;
}