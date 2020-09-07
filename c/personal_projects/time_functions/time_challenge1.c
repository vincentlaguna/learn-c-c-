#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define N 50
#define NUM 40
// Function Proto-types
void fillArray(double ar[], int n);
void showArray(const double ar[], int n);
int myComp(const void *p1, const void *p2);
// MAin Function
int main(void)
{
  /* // Challenge #1
  int i = 0;
  char str = '\0';
  // Use srand with seed
  srand(time(NULL));
  printf("%d\n", N);
  // Generate 50 random numbers (-0.5 to 0.5)
  for(i = 1; i <= N; i++)
  {
    printf("%0.4lf\n", (rand() % 2001 - 1000) / 2.e3);
  }
  */
  // Challenge #2
  double vals[NUM];
  fillArray(vals, NUM);
  
  /*
  0.Use srand() with seed
  
  2.First line of output: number of data
  3.Next 50 lines should be the 50 random numbers
  4.Sort an array of doubles from lowest to highest
  5.Create a function that takes a double array and a size parameter
  which generates some random double values
  6.void fillArray(double ar[], int n);
  7.Create a function that shows the array (takes a double array and size)
  8.void showArray(const double ar[], int n);
  9.Main should contain: create array, fill it with random numbers,
  display it, sort it using qsort, display the sorted array (0-15 doubles)
  10.Write a program that displays the current time
  11.Write a program to compute the number of seconds passed since
  the beginning of the current month
  */
  puts("Time challenge 1 TEST");
  return(0);
}

void fillArray(double ar[], int n)
{
  int index = 0;
  
  for(index = 0; index < n; index++)
    ar[index] = (double)rand() / ((double) rand() + 0.1);
}

void showArray(const double ar[], int n)
{
  int index;
  
  for(index = 0; index < n; index++)
  {
    printf("%9.4f ", ar[index]);
    if(index % 6 == 5)
      putchar('\n');
  }
  if(index % 6 != 0)
    putchar('\n');
}

int myComp(const void *p1, const void *p2)
{
  
}