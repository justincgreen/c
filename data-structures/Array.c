#include <stdio.h>

int main(void) {
  int nums[] = {7,8,9};
  int nums_size = sizeof(nums);
  int nums_length = nums_size / sizeof(nums[0]);

  printf("The array length is %i\n", nums_length);

  for(int i = 0; i < 3; i++) {
    printf("Element value is %i\n", nums[i]);
  }  
}