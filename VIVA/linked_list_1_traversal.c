#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){
    printf("The elements are = %d\n",ptr->data);
    ptr = ptr->next;
    }
}

int main(){
    struct Node* root;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    root = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    // First Node
    root->data = 7;
    root->next = second;

    // second Node
    second->data = 12;
    second->next = third;

    // third Node
    third->data = 14;
    third->next = fourth;

    // fourth Node
    fourth->data = 75;
    fourth->next = NULL;

    linkedListTraversal(root);

    return 0;
}
