// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     char data;
//     struct node *left;
//     struct node *right;
// };

// struct node *create()
// {
//     int choice;
//     char data;
//     struct node *newnode;
//     newnode = (struct node *)malloc(sizeof(struct node));
//     printf("Enter the data ('!' for no node): \n");
//     scanf("%c", &data);
//     if (data == '!')
//     {
//         return 0;
//     }
//     newnode->data = data;
//     newnode->left = create();
//     printf("Do you want to create right node (1/0) ?: \n");
//     scanf("%d", &choice);
//     if (choice)
//     {
//         newnode->right = create();
//     }
//     else
//     {
//         newnode->right = 0;
//     }
//     return newnode;
// }

// int main()
// {
//     struct node *root;
//     root = create();
//     printf("%c\n", root->data);
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
 
typedef struct node
{
char data;
struct node *left;
struct node *right;
} node;
 
node *create()
{
node *p;
char x;
printf("Enter data(! for no data):");
scanf("%c",&x);
if(x=='!')
return NULL;
p=(node*)malloc(sizeof(node));
p->data=x;
printf("Enter left child of %c:\n",x);
p->left=create();
 
printf("Enter right child of %c:\n",x);
p->right=create();
return p;
}

int main()
{
node *root;
root=create();
return 0;
}