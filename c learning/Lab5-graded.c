#include<stdio.h> 
#include<stdlib.h> 

void print_array(const int* arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
void print_range_index(const int* arr, int start, int end)
{
    printf("[%d..%d] -- { ", start, end);
    for (int i = start; i <= end; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}
void copy_reverse(const int* from, int* to, int size)
{
    for (int i = 0; i < size; i++)
    {
        to[size - i - 1] = from[i];
    }
}
int find_min_distance(const int* input, int size, int n1, int n2)
{
    int min = size;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == n1)
        {
            for (int j = 0; j < size; j++)
            {
                if (input[j] == n2 && abs(i - j) < min) min = abs(i - j);
            }
        }
    }
    if (min == size) return -1;
    return min;
}
int isendingwithzeros(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i; j < size;j++)
            {
                if (arr[j] != 0) return 0;
            }
        }
    }
    return 1;
}
void rearrange_update(int* arr, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            arr[i] *= 2;
            arr[i + 1] = 0;
        }
    }
    while (isendingwithzeros(arr, size) != 1)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == 0)
            {
                for (int j = i; j < size - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                arr[size - 1] = 0;
            }
        }
    }
}
void pick_subarrays(const int* arr, int size, int sum, int subarr_idx[][2], int* number_subarr_found)
{
    
    for (int i = 0; i < size; i++)
    {
        
        for (int j = 0; j < size - i; j++)
        {
            int tempsum = 0;
            for (int k = i; k < i + j; k++)
            {
                tempsum += arr[k];
            }
            if (tempsum == sum)
            {
                subarr_idx[*number_subarr_found][0] = i;
                subarr_idx[*number_subarr_found][1] = i+j-1;
                *number_subarr_found += 1;
            }
        }
    }
}
void print_subarrays(const int* arr, const int subarr_idx[][2], int number_subarr_found)
{
    for (int i = 0; i < number_subarr_found; i++)
    {
        print_range_index(arr, subarr_idx[i][0], subarr_idx[i][1]);
    }
}

int Lab5()
{
    int arr1[] = { 7, 9, 5, 11, 7, 4, 12, 6, 2, 11 };
    int size = sizeof(arr1) / sizeof(arr1[0]);

    // Part 0 (0 pts)
    printf("****************** Part 0 ******************\n");
    print_array(arr1, size);

    // Part 1 (0.5 pts)
    printf("****************** Part 1 ******************\n");
    
        print_range_index(arr1, 0, size - 1);
    
    // Part 2 (1 pts)
    printf("****************** Part 2 ******************\n");
    
        int arr2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        copy_reverse(arr1, arr2, size);
        print_array(arr2, size);
    
    // Part 3 (2 pts)
    printf("****************** Part 3 ******************\n");
    
        print_array(arr1, size);
        printf("The minimum distance between %d and %d is:  %d\n", 7, 11, find_min_distance(arr1, size, 7, 11));
        printf("The minimum distance between %d and %d is:  %d\n", 11, 7, find_min_distance(arr1, size, 11, 7));
        printf("The minimum distance between %d and %d is:  %d\n", 12, 11, find_min_distance(arr1, size, 12, 11));
        printf("The minimum distance between %d and %d is:  %d\n", 7, 13, find_min_distance(arr1, size, 7, 13));
    
    // Part 4 (2 pts)
    printf("****************** Part 4 ******************\n");
    
        int arr3[] = { 0, 3, 3, 3, 0, 0, 7, 7, 0, 9 };
        print_array(arr3, size);
        rearrange_update(arr3, size);
        print_array(arr3, size);
    
    // Part 5 (2.5 pts)
    printf("****************** Part 5 ******************\n");
    
        int arr4[] = { 3, 4, -7, 1, 3, 3, 1, -4 };
        size = sizeof(arr4) / sizeof(arr4[0]);
        int sum = 7;
        int subarr_idx[10][2];
        int number_subarr_found = 0;
        pick_subarrays(arr4, size, sum, subarr_idx, &number_subarr_found);

        print_array(arr4, size);
        printf("Found subarrays indexes [start end]:\n");
        for (int i = 0; i < number_subarr_found; i++)
        {
            printf("[");
            printf("%d %d", subarr_idx[i][0], subarr_idx[i][1]);
            printf("]\n");
        }

        printf("Found subarrays:\n");
        print_subarrays(arr4, subarr_idx, number_subarr_found);
    return 0;
}