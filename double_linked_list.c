#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next, *prev;
};

struct node *head, *temp, *newnode, *prevnode, *currentnode, *nextnode;

void print()
{
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}

void list()
{
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
            newnode->prev = 0;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Do you want to continue to insert the elements: (o,1)? - ");
        scanf("%d", &choice);
    }
    print();
}

void insert_beginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number to be inserted: ");
    scanf("%d", &newnode->num);
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    print();
}

void insert_ending()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number to be inserted: ");
    scanf("%d", &newnode->num);
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = 0;
    print();
}

void insert_given_position()
{
    int position, i;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number to be inserted: ");
    scanf("%d", &newnode->num);
    printf("Enter the position: ");
    scanf("%d", &position);
    temp = head;
    for (i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
    temp = newnode->next;
    temp->prev = newnode;
    printf("List after insertion is: ");
    print();
}

void deletion_beginning()
{
    if (head == 0)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;
        head = temp->next;
        free(temp);
        head->prev = 0;
    }
    print();
}

void deletion_ending()
{
    temp = head;
    while (temp->next != 0)
    {
        prevnode = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = 0;
    }
    else
    {
        prevnode->next = 0;
    }
    free(temp);
    print();
}

void deletion_given_position()
{
    int i, position;
    printf("Enter the position to be deleted: ");
    scanf("%d", &position);
    temp = head;
    for (i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    print();
}

void reverse_list()
{
    for (temp = head; temp != 0; temp = temp->next)
        ;
    head = temp;
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->num);
        temp = temp->prev;
    }
}

int main()
{
    int choice;
    list();
    printf("Select the operation type: \n");
    printf("1. Insert in beginning\n2. Insert at end\n3. Insert at given position\n4. Delete in beginning\n5. Delete at end\n6. Delete in given position\n7. Reverse the list\n");
    printf("Enter the operation type: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        insert_beginning();
        break;
    case 2:
        insert_ending();
        break;
    case 3:
        insert_given_position();
        break;
    case 4:
        deletion_beginning();
        break;
    case 5:
        deletion_ending();
        break;
    case 6:
        deletion_given_position();
        break;
    case 7:
        reverse_list();
        break;
    default:
        break;
    }
    return 0;
}