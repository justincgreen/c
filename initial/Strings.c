#include <stdio.h>
#include <string.h>

int main(void) {
  char wordArr[6] = {'H','e','l','l','o','\0'}; // array of characters
  char word[] = "Hello"; // String literal
  // printf("%s\n", word);

  int length = strlen(word);  
  // printf("String length is %i\n", length);

  char original[] = "Hello World!";
  char destination[20]; // make sure this array is big enough for original
  strcpy(destination, original);
  // printf("Copied string: %s\n", destination);

  char greeting[20] = "Hello, ";
  char name[] = "Justin";
  strcat(greeting, name);
  printf("Message: %s\n", greeting);
}