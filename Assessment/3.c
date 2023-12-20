#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void traversal(struct Node *root){
    while(root!=NULL){
        printf("%d\n",root->data);
        root = root->next;
    }
}
struct Node* insertAtFirst(struct Node *root, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = root;
    ptr->data = data;
    return ptr;
}
struct Node* between(struct Node *root, int data, int index){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = root;
    int i=0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return root;
}
struct Node* end(struct Node *root, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = root;
    while(p->next!=NULL){
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

    // traversal(root);
    // root = insertAtFirst(root,57);
    // between(root,57,2);
    end(root,57);
    traversal(root);

    return 0;
}
