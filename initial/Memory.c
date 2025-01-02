#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int myInt;
  float myFloat;
  double myDouble;
  char myChar;

  printf("%lu\n", sizeof(myInt)); // 4 bytes
  printf("%lu\n", sizeof(myFloat)); // 4 bytes
  printf("%lu\n", sizeof(myDouble)); // 8 bytes
  printf("%lu\n", sizeof(myChar)); // 1 byte

  // Static Memory
  // memory reserved for variables before the program runs.
  int students[20];
  printf("%lu\n", sizeof(students)); // 80 bytes = 20 * 4 bytes

  int *ptr;
  ptr = calloc(4, sizeof(*ptr));

  *ptr= 2;
  ptr[1] = 4;
  ptr[2] = 6;

  printf("%d\n", *ptr);
  printf("%d %d %d", ptr[1], ptr[2], ptr[3]);
}