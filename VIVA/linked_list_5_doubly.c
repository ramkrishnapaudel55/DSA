#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

void linkedListTraversalForward(struct Node *root){
    while(root!=NULL){
    printf("The elements are = %d\n",root->data);
    root = root->next;
    }
}

void linkedListTraversalBackward(struct Node *lastNode){
    struct Node* ptr = lastNode;
    while(ptr!=NULL){
    printf("The elements are = %d\n",ptr->data);
    ptr = ptr->prev;
    }
}

struct Node* insertAtTheBegining(struct Node *root, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = root;
    ptr->data = data;
    return ptr;
}

struct Node* insertInBetween(struct Node *root, int data, int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = root;

    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return root;
}

struct Node* insertAtTheEnd(struct Node *root, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = root;

    int i = 0;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return root;
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
    root->prev = NULL;
    root->data = 7;
    root->next = second;

    // second Node
    second->prev = root;
    second->data = 12;
    second->next = third;

    // third Node
    third->prev = second;
    third->data = 14;
    third->next = fourth;

    // fourth Node
    fourth->prev = third;
    fourth->data = 75;
    fourth->next = NULL;

    linkedListTraversalForward(root);
    printf("\n");
    // linkedListTraversalBackward(fourth);
    root = insertAtTheBegining(root, 50);
    // insertInBetween(root, 27 ,2);
    // insertAtTheEnd(root, 11);
    printf("\n");
    printf("Linked list after insertion\n");
    // linkedListTraversal(root);

    return 0;
}
