#include <stdio.h>

int main(void) {
  FILE *file = fopen("example.txt", "w");

  fprintf(file, "Hello, World!\n"); // Write a formatted string
  fprintf(file, "This is a line of text.\n"); // Write another line

  // Close the file
  fclose(file);
}