#include <stdio.h>
void myFunction() {
  printf("My function works\n");
}

void greeting(char name[]) {
  printf("Hello %s\n", name);
}

void foo(char name[], int age) {
  printf("Hello %s, You are %d years old\n", name, age);
}

void calculateSum(int x, int y) {
  int sum = x + y;
  printf("The sum is: %i\n", sum);
}

int main(void) {
  myFunction();
  greeting("Justin");
  foo("Justin", 36);
  calculateSum(1,2);
}