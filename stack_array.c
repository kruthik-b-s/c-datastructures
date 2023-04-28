#include <stdio.h>
#include <stdlib.h>
#define size 5
int top = -1, stack[size];

void disp()
{
    int i;
    if (top == -1)
    {
        printf("stack empty!!\n");
    }
    else
    {
        printf("Stack elements: ");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void push()
{
    if (top == size - 1)
    {
        printf("stack overflow!!\n");
    }
    else
    {
        top++;
        printf("Enter the element to be pushed/inserted: ");
        scanf("%d", &stack[top]);
    }
    disp();
}

void pop()
{
    int temp;
    if (top == -1)
    {
        printf("stack is empty!!\n");
    }
    else
    {
        temp = stack[top];
        stack[top] = 0;
        top--;
    }
    disp();
}

void peek()
{
    if (top == -1)
    {
        printf("stack underflow!!\n");
    }
    else
    {
        printf("Last inserted element: %d \n", stack[top]);
    }
}

int isempty()
{
    return top == -1;
}

int isfull()
{
    return top == size - 1;
}

int main()
{
    int choice, res1, res2;
    while (1)
    {
        printf("1. Push an element\n2. Pop an element\n3. Peek an element\n4. Display all elements\n5. check if empty\n6. check if full\n7. exit\n");
        printf("Enter the operation to be performed: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            disp();
            break;
        case 5:
            res1 = isempty();
            if (res1)
                printf("Stack is empty!!");
            break;
        case 6:
            res2 = isfull();
            if (res2)
                printf("Stack is full!!");
            break;
        case 7:
            exit(0);
        }
        printf("-----------------------------------\n\n");
    }
    return 0;
}