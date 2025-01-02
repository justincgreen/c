#include <stdio.h>

int main(void) {
  int grades[] = {1,2,3};
  int size = sizeof(grades);
  int length = size / sizeof(grades[0]);

  // printf("%i\n", length);

  for(int i = 0; i < length; i++ ) {
    printf("%i is the index and the element is %i\n", i, grades[i]);
  }
 }