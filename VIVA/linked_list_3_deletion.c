#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void linkTraversal(struct Node *root){
    struct Node *ptr = root;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node* deleteAtBegining(struct Node *root){
    struct Node *ptr = root;
    root = root->next;
    ptr->next = NULL;
    free(ptr);
    return root;
}

struct Node* deleteInBetween(struct Node *root, int index){
    struct Node *ptr = root;
    struct Node *q = root->next;

    int i = 0;
    while(ptr!=NULL && i<index-1)
    {
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    ptr->next = q->next;
    free(q);

    return root;

}

struct Node* deleteAtEnd(struct Node *root){
    struct Node *ptr = root;
    struct Node *q = root->next;
    int i = 0;
    while (q->next!=NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;

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
    fourth->next = NULL;
    
    linkTraversal(root);
    printf("\n");
    // root = deleteAtBegining(root);
    root = deleteInBetween(root,2);
    // deleteAtEnd(root);
    printf("The element after performing operation:\n");
    linkTraversal(root);

    return 0;
}










































// struct Node* deleteInBetween(struct Node *root, int index){
//     if (root == NULL || index < 0) {
//         printf("Invalid input\n");
//         return root;
//     }

//     if (index == 0) {
//         struct Node *temp = root;
//         root = root->next;
//         free(temp);
//         return root;
//     }

//     struct Node *ptr = root;
//     for (int i = 0; ptr != NULL && i < index - 1; i++)
//     {
//         ptr = ptr->next;
//     }

//     if (ptr == NULL || ptr->next == NULL) {
//         printf("Index out of range\n");
//         return root;
//     }

//     struct Node *q = ptr->next;
//     ptr->next = q->next;
//     free(q);

//     return root;
// }
