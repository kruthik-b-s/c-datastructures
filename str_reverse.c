#include<stdio.h>
#define size 10
char stack[size];
int sp=-1;

void push(char data){
    if(sp==size-1){
        printf("Stack is full");
    }
    else{
        sp++;
        stack[sp]=data;
    }
}

void disp(){
    int i;
    if(sp==-1){
        printf("Empty stack");
    }
    else{
        for(i=sp;i>-1;i--){
            printf("%c",stack[i]);
        }
        printf("\n");
    }
}

void reverse(char string[]){
    int i;
    for(i=0;string[i];i++){
        push(string[i]);
    }
    disp();
}

int main(){
    char string[size];
    printf("Enter the string of max size %d: ",size);
    scanf("%s",string);
    reverse(string);
    return 0;
}