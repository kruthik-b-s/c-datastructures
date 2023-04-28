#include <stdio.h>

int main()
{
    int arr[20];
    int status1, status2, i, j, k, n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        status1 = 0;
        for (j = 0; j < i; j++)
        { // check the no. in previous index
            if (arr[i] == arr[j])
            {
                status1 = 1; // if no. is equal
                break;
            }
        }
        if (status1 == 0)
        {
            status2 = 0;
            for (k = i + 1; k < n; k++)
            { // check the no. in further indeces
                if (arr[i] == arr[k])
                {
                    status2 = 1;
                } // if no. is equal
                break;
            }
        }
        if (status2 == 0 && status1 == 0)
        {
            printf("%d\t", arr[i]);
        }
    }
    printf("\n");

    return 0;
}