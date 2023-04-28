#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *newnode(int data){
    struct node *node;
    node = (struct node *)malloc(sizeof(struct node));
    node->data=data;
    node->left=0;
    node->right=0;
    return node;
}

void printpostorder(struct node *node){
    if(node==0){
        return;
    }
    printpostorder(node->left);
    printpostorder(node->right);
    printf("%d ",node->data);
}

void printinorder(struct node *node){
    if(node==0){
        return;
    }
    printinorder(node->left);
    printf("%d ",node->data);
    printinorder(node->right);
}

void printpreorder(struct node *node){
    if(node==0){
        return;
    }
    printf("%d ",node->data);
    printpreorder(node->left);
    printpreorder(node->right);
}

int main(){
    struct node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    printf("preorder traversal of binary tree is\n ");
    printpreorder(root);
    printf("\n");
    printf("inorder traversal of binary tree is\n");
    printinorder(root);
    printf("\n");
    printf("postorder traversal of binary tree is\n");
    printpostorder(root);
    printf("\n");
    return 0;
}