#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

int main()
{
    struct node *temp, *head, *newnode;
    int choice = 1;
    head = 0;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Ente the number to be inserted: ");
        scanf("%d", &newnode->num);
        newnode->next = 0;
        if (head == 0)
        {
            temp = newnode;
            head = temp;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue to insert the elements: (o,1)? - ");
        scanf("%d", &choice);
    }
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}