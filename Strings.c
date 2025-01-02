#include <stdio.h>
#include <string.h>

int main(void) {
  char wordArr[6] = {'H','e','l','l','o','\0'}; // array of characters
  char word[] = "Hello"; // String literal
  // printf("%s\n", word);

  int length = strlen(word);  
  printf("String length is %i\n", length);
}