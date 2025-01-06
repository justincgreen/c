#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if(!newNode) {
    printf("Memory Allocation failed \n");
    exit(1);
  }
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
  if(root == NULL) {
    root = createNode(data);
    return root;
  }

  if(data < root->data) {
    root->left = insertNode(root->left, data);
  }else {
    root->right = insertNode(root->right,data);
  }

  return root;
}

// Function to perform in-order traversal of the binary tree
void inOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Function to free the memory used by the tree
void freeTree(struct Node* root) {
    if (root == NULL) return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
  struct Node* root = NULL;

  root = insertNode(root, 50);
  insertNode(root, 30);
  insertNode(root, 70);
  insertNode(root, 20);
  insertNode(root, 40);
  insertNode(root, 60);

  printf("In-order traversal of the binary tree: ");
  inOrderTraversal(root);
  printf("\n");

  // Free the memory used by the tree
  freeTree(root);
}