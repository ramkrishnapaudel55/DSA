#include<stdio.h>
#include<stdlib.h>
struct stack{
    int TOS;
    int size;
    int *stack;
};
void push(struct stack *s,int n){
    if(s->TOS == s->size - 1){
        printf("Overflow\n");
    }else{
        s->TOS++;
        s->stack[s->TOS] = n;
    }
}

int pop(struct stack *s){
    int a = -1;
    if(s->TOS == -1){
        printf("Underflow\n");
    }else{
        a = s->stack[s->TOS];
        printf("Popped Item : %d\n",a);
        s->TOS--; 
    }
    return a;
}

void display(struct stack *s){
    int i;
    if(s->TOS == -1){
        printf("Underflow\n");
    }else{
        for(i=0;i<=(s->TOS);i++){
            printf("%d\t",s->stack[i]);
        }
    }
}

int main(){
    struct stack s;
    s.TOS = -1;
    s.size = 10;
    s.stack = (int *)malloc(s.size*(sizeof(int)));
    int choice,num;
    while (1)
    {
    printf("\n-------* Stack Operation *-------\n");
    printf("1.Push                             \n");
    printf("2.Pop                              \n");
    printf("3.Display                          \n");
    printf("4.Exit                             \n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("\nEnter the number to push:");
        scanf("%d",&num);
        push(&s,num);
        break;

    case 2:
        pop(&s);
        break;

    case 3:
        display(&s);
        break;

    case 4:
        exit(0);
        break;
    
    default:
        printf("Invalid Input");
        break;
    }
    }
    return 0;
}