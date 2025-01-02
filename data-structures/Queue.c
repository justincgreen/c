#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Queue {
  int items[MAX]; // array to store queue elements
  int front; // index of front element;
  int rear; // index of rear element;
} Queue;

// function to initialize queue
void initQueue(Queue* q) {
  q->front = -1;
  q->rear = -1;
}

// check if queue is empty
int isEmpty(Queue* q) {
  return q->front == -1;
}

// check if queue is full
int isFull(Queue* q) {
  return q->rear == MAX -1;
}

// Enqueue (insert an element)
void enqueue(Queue* q, int value) {
  if(isFull(q)) {
    printf("Queue overflow! Cannot enqueue %d\n", value);
    return;
  }
  if(isEmpty(q)) {
    q->front = 0;    
  }
  q->rear++;
  q->items[q->rear] = value;
  printf("Enqueued: %d\n", value);
}

// Dequeue (remove an element)
int dequeue(Queue* q) {
  if (isEmpty(q)) {
    printf("Queue underflow! Cannot dequeue.\n");
    return -1; // Return -1 if queue is empty
  }
  int value = q->items[q->front];
  if(q->front == q->rear) {
    // if queue becomes empty after dequeueing
    q->front = -1;
    q->rear = -1;
  } else {
    q->front++;
  }
  return value;
}

// Peek (view front element)
int peek(Queue* q) {
  if(isEmpty(q)) {
    printf("Queue is empty! Cannot peek.\n");
    return -1; // Return -1 if queue is empty
  }
  return q->items[q->front];
}

// Display the queue
void display(Queue* q) {
  if(isEmpty(q)){
    printf("Queue is empty!\n");    
  }
  printf("Queue: ");
  for(int i = q->front; i <= q->rear; i++) {
    printf("%d ", q->items[i]);
  }
  printf("\n");
}

int main(void) {
  Queue q;
  initQueue(&q);

  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  display(&q);

  printf("Dequeued: %d\n", dequeue(&q));
  display(&q);

  printf("Front element is: %d\n", peek(&q));
}