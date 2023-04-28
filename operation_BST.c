#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newnode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = 0;
    return temp;
}

void inorder(struct node *root)
{
    if (root != 0)
    {
        inorder(root->left);
        printf("%d->", root->key);
        inorder(root->right);
    }
}

struct node *minvaluenode(struct node *node)
{
    struct node *current = node;
    while (current && current->left != 0)
    {
        current = current->left;
    }
    return current;
}

struct node *deletenode(struct node *root, int key)
{
    if (root == 0)
    {
        return root;
    }
    if (key < root->key)
        root->left = delete (root->left, key);
    else if (key > root->key)
        root->right = deletenode(root->right, key);
    else{
        if(root->left==0){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==0){
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node *temp=minvaluenode(root->right);
        root->key=temp->key;
        root->right=deletenode(root->right,temp->key);
    }
}