#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkTraversal(struct Node *root){
    struct Node *ptr = root;
    do{
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    } while(ptr != root);
}

struct Node* deleteAtFirst(struct Node *root){
    if (root == NULL) {
        return NULL; // Handle the case of an empty list
    }

    struct Node *temp = root;
    struct Node *last = root;

    while (last->next != root)
    {
        last = last->next;
    }
    
    struct Node *newRoot = root->next;
    last->next = newRoot;

    free(temp);
    return newRoot;
}

int main(){
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    root->data = 1;
    root->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = root;
    
    linkTraversal(root);
    printf("\n");
    root = deleteAtFirst(root);
    linkTraversal(root);

    return 0;
}
