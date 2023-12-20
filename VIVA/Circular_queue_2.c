#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueue(struct Queue *q, int val) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("\nQueue full\n\n");
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
        if (q->front == -1) {
            q->front = 0;
        }
    }
}

int dequeue(struct Queue *q) {
    int a = -1;
    if (q->front == -1) {
        printf("\nQueue is empty\n\n");
    } else {
        a = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % q->size;
        }
    }
    return a;
}

void display(struct Queue *q) {
    if (q->front == -1) {
        printf("\nQueue is empty\n\n");
    } else {
        printf("\n");
        int i = q->front;
        do {
            printf("%d\t", q->arr[i]);
            i = (i + 1) % q->size;
        } while (i != (q->rear + 1) % q->size);
        printf("\n\n");
    }
}

int main() {
    struct Queue q;
    q.size = 5;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int n;
    int choice;

    while (1) {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value of the number: ");
                scanf("%d", &n);
                enqueue(&q, n);
                break;

            case 2:
                printf("\nDequeued item = %d\n\n", dequeue(&q));
                break;

            case 3:
                display(&q);
                break;

            case 4:
                exit(0);

            default:
                printf("Incorrect choice\n");
        }
    }

    return 0;
}
