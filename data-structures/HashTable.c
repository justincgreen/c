#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10

typedef struct Node {
  char key[50];
  int value;
  struct Node* next;
} Node;

// Define the hash table
typedef struct HashTable {
  Node* buckets[TABLE_SIZE];
} HashTable;

// Hash Function
unsigned int hash(const char* key) {
  unsigned int hash = 0;
  for(int i = 0; key[i] != '\0'; i++) {
    hash = (hash * 31 + key[i]) % TABLE_SIZE;
  }
  return hash;
}

// create a new node
Node* createNode(const char* key, int value) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->key, key);
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

// Initialize the hashtable
void initHashTable(HashTable* table) {
  for(int i = 0; i < TABLE_SIZE; i++) {
    table->buckets[i] = NULL;
  }
}

// Insert a key-value pair into the hash table
void insert(HashTable* table, const char* key, int value) {
  unsigned int index = hash(key);
  Node* newNode = createNode(key, value);
  newNode->next = table->buckets[index];
  table->buckets[index] = newNode;
  printf("Inserted key: %s, value: %d at index: %d\n", key, value, index);
}

// Search for a value by key
int search(HashTable* table, const char* key) {
  unsigned int index = hash(key);
  Node* current = table->buckets[index];
  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      return current->value; // Key found
    }
    current = current->next;
  }
  return -1; // Key not found
}

// Delete a key-value pair from the hash table
void delete(HashTable* table, const char* key) {
  unsigned int index = hash(key);
  Node* current = table->buckets[index];
  Node* prev = NULL;

  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      if (prev == NULL) {
        table->buckets[index] = current->next; // Remove the head node
      } else {
        prev->next = current->next; // Bypass the current node
      }
      free(current);
      printf("Deleted key: %s\n", key);
      return;
    }
    prev = current;
    current = current->next;
  }
  printf("Key not found: %s\n", key);
}

// Print the hash table
void printHashTable(HashTable* table) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("Bucket %d: ", i);
    Node* current = table->buckets[i];
    while (current != NULL) {
      printf("[%s: %d] -> ", current->key, current->value);
      current = current->next;
    }
    printf("NULL\n");
  }
}

int main(void) {
HashTable table;
  initHashTable(&table);

  insert(&table, "apple", 10);
  insert(&table, "banana", 20);
  insert(&table, "orange", 30);
  insert(&table, "grape", 40);

  printHashTable(&table);

  printf("Search for 'apple': %d\n", search(&table, "apple"));
  printf("Search for 'mango': %d\n", search(&table, "mango"));

  delete(&table, "banana");
  printHashTable(&table);
}