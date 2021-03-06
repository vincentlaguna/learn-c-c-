#include <stdio.h>
#include <stdlib.h>
// Function Prototypes
void display_method_a(int *arr, int row, int col);
void display_method_b(int (*arr)[3], int row, int col);
void display_method_c(int arr[][3], int row, int col);
// Main Function
int main(void)
{
  int i, j;
  int arr[3][3] = 
  {
    {1, 100, 1000},
    {2, 200, 2000},
    {3, 300, 3000}
  };
  
  printf("\n3 different methods of displaying the array -> \n\n");
  display_method_a(arr, 3, 3);
  printf("\n");
  display_method_b(arr, 3, 3);
  printf("\n");
  display_method_c(arr, 3, 3);
  printf("\n");
  getchar();
  
  return(0);
}
// Function Definitions
void display_method_a(int *arr, int row, int col)
{
  int i, j;
  
  for(i = 0; i < row; i++)
  {
    for(j = 0; j < col; j++)
    {
      printf("%d ", *(arr + ((i * col) + j)));
    }
    printf("\n");
  }
}

void display_method_b(int (*arr)[3], int row, int col)
{
  int i, j;
  int *ptr;
  
  for(i = 0; i < row; i++)
  {
    ptr = arr + i;
    
    for(j = 0; j < col; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

void display_method_c(int arr[][3], int row, int col)
{
  int i, j;
  
  for(i = 0; i < row; i++)
  {
    for(j = 0; j < col; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}