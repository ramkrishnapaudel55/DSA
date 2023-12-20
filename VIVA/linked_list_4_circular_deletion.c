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
    }while(ptr!=root);
}

struct Node* deleteAtFirst(struct Node *root){
    struct Node *ptr = root;

    while (ptr->next != root)
    {
        ptr = ptr->next;
    }

    struct Node *q = root->next;
    free(root);
    return q;
}

// struct Node* deleteAtFirst(struct Node *root){
//     if (root == NULL) {
//         return NULL;
//     }

//     struct Node *ptr = root;
//     struct Node *q = root;

//     root = root->next;
//     ptr->next = NULL;

//     while (q->next != ptr)
//     {
//         q = q->next;
//     }
//     q->next = root;

//     free(ptr);
//     return root;
// }


struct Node* insertInBetween(struct Node *root,int num, int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = root;

    int i = 0;
    while (i!=index-1)
    {
        q = q->next;
        i++;
    }
    ptr->data = num;
    ptr->next = q->next;
    q->next = ptr;

    return root;

}

struct Node* insertAtEnd(struct Node *root, int num){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = num;
    struct Node *q = root;
    while (q->next!=root)
    {
        q = q->next;
    }
    q->next = ptr;
    ptr->next = root;
    

    return root;
}

int main(){
    struct Node *root;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    root = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

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
    // root = insertInBetween(root,57835,2);
    // insertAtEnd(root,57835);
    printf("The element after performing operation:\n");
    linkTraversal(root);

    return 0;
}