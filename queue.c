#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum size of the queue

typedef struct {
    int queue[MAX_SIZE];
    int front, rear;
} Queue;

void initializeQueue(Queue* q) {
    q->front = q->rear = -1;
}

bool isQueueEmpty(Queue* q) {
    return q->front == -1;
}

bool isQueueFull(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue* q, int x) {
    if (!isQueueFull(q)) {
        if (isQueueEmpty(q))
            q->front = q->rear = 0;
        else
            q->rear = (q->rear + 1) % MAX_SIZE;
        q->queue[q->rear] = x;
    } else {
        printf("Queue is full, cannot enqueue %d\n", x);
    }
}

int dequeue(Queue* q) {
    if (!isQueueEmpty(q)) {
        int x = q->queue[q->front];
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front = (q->front + 1) % MAX_SIZE;
        return x;
    } else {
        printf("Queue is empty, cannot dequeue\n");
        return -1; // Or any appropriate value indicating failure
    }
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 4);
    enqueue(&queue, 1);
    enqueue(&queue, 3);

    printf("Dequeued from queue: %d\n", dequeue(&queue));
    printf("Dequeued from queue: %d\n", dequeue(&queue));
    printf("Dequeued from queue: %d\n", dequeue(&queue));

    return 0;
}


*****************
OUTPUT
*****************

Q 4 1 3
  
Dequeued from queue: 4
Dequeued from queue: 1
Dequeued from queue: 3
