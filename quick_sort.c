#include <stdio.h>

int partition(int a[], int lb, int ub)
{
    int pivot, start, end, temp;
    pivot = a[lb];
    start = lb;
    end = ub;
    while (start < end)
    {
        while (a[start] <= pivot)
            start++;
        while (a[end] > pivot)
            end--;
        if (start < end)
        {
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;
    return end;
}

void quick_sort(int a[], int lb, int ub)
{
    int pos;
    if (lb < ub)
    {
        pos = partition(a, lb, ub);
        quick_sort(a, lb, pos - 1);
        quick_sort(a, pos + 1, ub);
    }
}

int main()
{
    int a[100], lb, ub, size, i;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    printf("Enter the array elements: ");
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);
    lb = 0;
    ub = size - 1;
    quick_sort(a, lb, ub);
    printf("The sorted elements are: ");
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}