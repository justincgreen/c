#include <stdio.h>

int main(void) {
  int a = 5;
  int b = 8;

  int result = (a > b);
  printf("%i\n", result); // 0 for false

  int num = 10;
  num += 5; // adds 5 to 10 and assigns it to num
  printf("%i\n", num); // 15

  int mynum = 11;
  mynum++; // Increments mynum by 1
  printf("%i\n", mynum); // 12
}