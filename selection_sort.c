#include <stdio.h>
int main()
{
    int a[100], size, i, j, min;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the array elements: ");
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
            a[i] ^= a[min] ^= a[i] ^= a[min];
    }
    printf("The sorted array is: ");
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}