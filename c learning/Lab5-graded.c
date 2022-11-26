#include<stdio.h> 
#include<stdlib.h> 

void print_array(const int* arr, int size);
void print_range_index(const int* arr, int start, int end);
void copy_reverse(const int* from, int* to, int size);
int find_min_distance(const int* input, int size, int n1, int n2);
void rearrange_update(int* arr, int size);
void pick_subarrays(const int* arr, int size, int sum, int subarr_idx[][2], int* number_subarr_found);
void print_subarrays1(const int* arr, const int subarr_idx[][2], int number_subarr_found);

void print_array_info(const int* arr, int size, int array_number);
void copy_shift(const int* from, int* to, int size, int shift);
int count_clumps(const int* arr, int size);
int check_subset(const int* set, int set_size, const int* query, int query_size);
void find_min_max_k(const int* arr, int size, int k, int subarr_min_max[][2], int* number_subarr_found);
void print_subarrays2(const int* arr, int k, const int subarr_min_max[][2], int subarr_size);

void version_a5();
void version_b5();

int Lab5()
{
    int choice;
    printf("\nChoose version ( A - 1  B - 2 ): ");
    if (scanf("%d",&choice) == 1)
    {
        switch (choice)
        {
        case 1:
            version_a5();
            break;
        case 2:
            version_b5();
            break;
        default:
            break;
        }
    }
    return 0;
}
/**************************** VERSION A ****************************/
void version_a5()
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
    print_subarrays1(arr4, subarr_idx, number_subarr_found);
}
/**************************** VERSION B ****************************/
void version_b5()
{
    int arr1[] = { 17, 42, 42, 7, 24, 24, 24, 17, 54, 17 };
    int size = sizeof(arr1) / sizeof(arr1[0]);

    // Part 0 (0 pts)
    printf("****************** Part 0 ******************\n");
    print_array(arr1, size);

    // Part 1 (0.5 pts)
    printf("****************** Part 1 ******************\n");
    
        print_array_info(arr1, size, 1);
    
    // Part 2 (1 pts)
    printf("****************** Part 2 ******************\n");
    
        int arr2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        copy_shift(arr1, arr2, size, 2);
        print_array(arr2, size);
    
    // Part 3 (2 pts)
    printf("****************** Part 3 ******************\n");
    
        print_array(arr1, size);
        printf("The number of clumps in the array is:  %d\n", count_clumps(arr1, size));
    
    // Part 4 (2 pts)
    printf("****************** Part 4 ******************\n");
    
        int arr3[] = { 17, 42, 7, 24, 54 };
        int size3 = sizeof(arr3) / sizeof(arr3[0]);

        print_array_info(arr1, size, 1);
        print_array_info(arr3, size3, 2);
        if (check_subset(arr1, size, arr3, size3))
            printf("Array #2 is the subset of array #1\n");
        else
            printf("Array #2 is not the subset of array #1\n");

        arr3[0] = 77;
        printf("\n");
        print_array_info(arr1, size, 1);
        print_array_info(arr3, size3, 2);
        if (check_subset(arr1, size, arr3, size3))
            printf("Array #2 is the subset of array #1\n");
        else
            printf("Array #2 is not the subset of array #1\n");
    
    // Part 5 (2.5 pts)
    printf("****************** Part 5 ******************\n");
    
        int arr4[] = { 1, 3, 6, 21, 4, 9, 12, 3, 16, 10 };
        size = sizeof(arr4) / sizeof(arr4[0]);
        int k = 4;
        int subarr_min_max[10][2];
        int number_subarr_found = 0;
        find_min_max_k(arr4, size, k, subarr_min_max, &number_subarr_found);

        print_array(arr4, size);
        printf("The length of each subarray is: %d\n", k);
        printf("Found min-max (for all subarrays of given length):\n");
        for (int i = 0; i < number_subarr_found; i++)
        {
            printf("[");
            printf("%d %d", subarr_min_max[i][0], subarr_min_max[i][1]);
            printf("]\n");
        }

        printf("Found subarrays and their min-max values:\n");
        print_subarrays2(arr4, k, subarr_min_max, number_subarr_found);
    
}


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
    for (int i = 0; i < size - 1; i++)
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
                subarr_idx[*number_subarr_found][1] = i + j - 1;
                *number_subarr_found += 1;
            }
        }
    }
}
void print_subarrays1(const int* arr, const int subarr_idx[][2], int number_subarr_found)
{
    for (int i = 0; i < number_subarr_found; i++)
    {
        print_range_index(arr, subarr_idx[i][0], subarr_idx[i][1]);
    }
}

void print_array_info(const int* arr, int size, int array_number)
{
    printf("Array #%d -- { ",array_number);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}
void copy_shift(const int* from, int* to, int size, int shift)
{
    for (int i = 0, j = shift; i < size; i++, j++)
    {
        if (j == size) j = 0;
        to[i] = from[j];
    }
}
int count_clumps(const int* arr, int size)
{
    int number = 0;
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            number += 1;
            for (int j = i + 2;j < size;j++)
            {
                if (arr[j] == arr[i]) i++;
                else break;
            }
        }
    }
    return number;
}
int check_subset(const int* set, int set_size, const int* query, int query_size)
{
    int contains = 0;
    for (int i = 0; i < query_size;i++)
    {
        contains = 0;
        for (int j = 0; j < set_size; j++)
        {
            if (set[j] == query[i]) contains = 1;
        }
        if (contains == 0) return 0;
    }
    return 1;
}
void find_min_max_k(const int* arr, int size, int k, int subarr_min_max[][2], int* number_subarr_found)
{
    for (int i = 0; i < size - k+1; i++)
    {
        int min = INT_MAX;
        int max = INT_MIN;
        for (int j = 0; j < k; j++)
        {
            if (arr[i + j] < min) min = arr[i + j];
            if (arr[i + j] > max) max = arr[i + j];
        }
        subarr_min_max[i][0] = min;
        subarr_min_max[i][1] = max;
        *number_subarr_found += 1;
    }
}
void print_subarrays2(const int* arr, int k, const int subarr_min_max[][2], int subarr_size)
{
    for (int i = 0; i < subarr_size;i++)
    {
        if (i != 0) printf("\n");
        printf("Array #%d -- { ", i);
        for (int j = i; j < i+k; j++)
        {
            printf("%d ",arr[j]);
        }
        printf("}");
        printf("\n[min: %d, max: %d]", subarr_min_max[i][0], subarr_min_max[i][1]);
    }
}