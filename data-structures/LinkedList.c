#include <stdio.h>
#include <stdlib.h>
// Define the structure for a singly linked list node
struct Node {
  int data; // data part of the node
  struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// function to print the linked list
void printList(struct Node* head) {
  struct Node* temp = head;
  while (temp != NULL) {
    printf("%d ->", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main(void) {
  // Create the first node
  struct Node* head = createNode(10);

  // Add more nodes
  head->next = createNode(20);
  head->next->next = createNode(30);

  // print the linked list
  printf("Linked list: ");
  printList(head);

  // free allocated memory
  struct Node* temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}