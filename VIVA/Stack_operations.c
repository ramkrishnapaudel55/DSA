#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE];
int TOS=-1;

void push(int num){
    if(TOS==SIZE-1){
        printf("Stack is overflow\n");
    }else{
        TOS++;
        stack[TOS]=num;
    }
}
int pop(){
    int data;
    if(TOS==-1){
        printf("Stack underflow\n");
    }else{
        data=stack[TOS];
        printf("\n Popped item = %d",data);
        TOS--;
    }
    return data;
}
void display(){
    int i;
    if(TOS==-1){
        printf("\nStack is Underflow");
    }else{
        for(i=0;i<=TOS;i++){
            printf("%d\t",stack[i]);
        }
    }
}
void main(){
    int choice,n;
    while(1){
        printf("\n**** Operation ****\n");
        printf("\n1.Push \n2.Pop \n3.Display \n4.Exit \n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter a number that you want to push: ");
                scanf("%d",&n);
                push(n);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(1);

            default:
                printf("Please enter the valid input");
        }
    }
}
