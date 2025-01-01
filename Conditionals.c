#include <stdio.h>
int main(void) {
  int age;

  printf("Please enter your age: ");
  scanf("%i", &age);

  if(age < 18) {
    printf("You need to be 18 or older to continue\n");
  }else {
    printf("You may continue\n");
  }
}