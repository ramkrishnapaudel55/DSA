#include <stdio.h>
#include <stdlib.h>

// Node definition for a doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to traverse a doubly linked list (forward traversal)
void traverse_double_linked_list(struct Node* head) {
    struct Node* current = head;

    printf("Forward Traversal: ");
    while (current != NULL) {
        printf("%d ", current->data); // Access the data or perform operations on the node
        current = current->next; // Move to the next node
    }
    printf("\n");
}

// Function to traverse a doubly linked list (backward traversal)
void traverse_double_linked_list_backward(struct Node* tail) {
    struct Node* current = tail;

    printf("Backward Traversal: ");
    while (current != NULL) {
        printf("%d ", current->data); // Access the data or perform operations on the node
        current = current->prev; // Move to the previous node
    }
    printf("\n");
}

// Function to free the memory used by the doubly linked list
void free_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the end of the doubly linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    // Traverse the doubly linked list forward
    traverse_double_linked_list(head);

    // Find the tail node (last node) for backward traversal
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // Traverse the doubly linked list backward
    traverse_double_linked_list_backward(tail);

    // Free the memory used by the doubly linked list
    free_list(head);

    return 0;
}
