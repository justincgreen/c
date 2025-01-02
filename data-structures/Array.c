#include <stdio.h>

int main(void) {
  int nums[] = {7,8,9};
  int nums_size = sizeof(nums);
  int nums_length = nums_size / sizeof(nums[0]);

  // printf("The array length is %i\n", nums_length);

  // for(int i = 0; i < 3; i++) {
  //   printf("Element value is %i memory address is %p\n", nums[i], (void*)&nums[i]);
  // }  

  int numbers[3] = {10,11,12};
  int numbers_size = sizeof(numbers); // 12 bytes =  3 numbers * 4 bytes
  int numbers_length = numbers_size / sizeof(numbers[0]); 
  
  for(int i = 0; i < numbers_length; i++) {
    printf("%i\n", numbers[i]);
  }
}