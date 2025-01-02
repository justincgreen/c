#include <stdio.h>
#include <stdlib.h>

# define MAX 100 // max stack size

typedef struct Stack {
  int top; // index of top element
  int items[MAX]; // Array to hold stack elements
} Stack;

// Initialize the stack
void initStack(Stack* stack) {
  stack->top = -1; // set top to -1 (stack is empty)
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
  return stack->top == -1;
}

// Check if the stack is full
int isFull(Stack* stack) {
  return stack->top == MAX - 1;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
  if(isFull(stack)) {
    printf("Stack overflow! Cannot push %d\n", value);
  }
  stack->items[++stack->top] = value;
  printf("%d pushed onto the stack \n", value);
}

// Pop an element from the stack
int pop(Stack* stack) {
  if(isEmpty(stack)) {
    printf("Stack underflow! Cannot pop.\n");
    return -1; // empty stack
  }
  return stack->items[stack->top--];
}

// Peek at the top element of the stack
int peek(Stack* stack) {
  if(isEmpty(stack)) {
    printf("Stack is empty! Cannot peek.\n");
    return -1;
  }
  return stack->items[stack->top];
}

int main(void) {
  Stack myStack;
  initStack(&myStack);

  // Add to stack
  push(&myStack, 10);
  push(&myStack, 20);
  push(&myStack, 30);

  printf("Top element is %d\n", peek(&myStack));

  printf("Popped: %d\n", pop(&myStack));
  printf("Popped: %d\n", pop(&myStack));
  printf("Popped: %d\n", pop(&myStack));

  if (isEmpty(&myStack)) {
    printf("Stack is now empty.\n");
  }
}