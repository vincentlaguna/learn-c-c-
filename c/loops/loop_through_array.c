#include <stdio.h>

int main(void)
{
  int numbers[3] = {101, 102, 103};
  int size = sizeof(numbers) / sizeof(numbers[0]);
  int *p = numbers;
  
  for(int i = 0; i < size; i++)
  {
    printf("[%d]\n", p[i]);
  }
  int *end = p + size;
  
  for(; p != end; ++p)
  {
    printf("[%d]\n", *p);
  }
  printf("sizeof(numbers) [%d]\nsizeof(p) [%d]\n", 
  (int) sizeof(numbers), (int) sizeof(p));
  return 0;
}