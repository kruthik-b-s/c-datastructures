#include <stdio.h>
int main()
{
    int a[100], size, i, j, temp;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the array elements: ");
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);
    for (i = 1; i < size; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    printf("The sorted array is: ");
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}