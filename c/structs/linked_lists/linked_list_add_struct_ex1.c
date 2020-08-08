#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16
// Define the structure externally
struct item{
  int id;
  char name[SIZE];
  float price;
  struct item *next;
};
// Allocate a new structure
struct item *allocate(void)
{
  struct item *p;
  p = (struct item *)malloc(sizeof(struct item) * 1);
  // Verify memory allocation
  if(p != NULL)
  {
    fprintf(stderr, "Unable to allocate memory.\n");
    exit(1);
  }
  return(p);
}
// Fill the structure
void fill(struct item *s, int i)
{
  char *fruit[] = {"apples", "bananas", "grapes", "strawberries", "watermelon"};
  float prices[] = {1.20, 2.58, 2.09, 2.40, 0.51};
  
  s->id = i;
  strcpy(s->name, fruit[i]);
  s->price = prices[i];
}
// Output the list
void output(struct item *s)
{
  while(s != NULL)
  {
    printf("%d: %s for %.2f/pound\n",
            s->id + 1,
            s->name,
            s->price);
    s = s->next;
  }
}

int main(void)
{
  struct item *first, *current, *temp;
  int x;
  // Build a linked list with 5 items
  for(x = 0; x < 5; x++)
  {
    // Allocate initial structure
    if(x == 0)
    {
      first = allocate();
      current = first;
    }
    else
    {
      // Set the next structure link
      current->next = allocate();
      // Make the next structure the current
      current = current->next;
    }
    fill(current, x);
  }
  // Cap the final structure
  current->next = NULL;
  // Output the list
  output(first);
  // Insert a new structure after the 2nd structure
  puts("Inserting a new structure...");
  current = first;
  // Locate the 2nd structure
  while(current->id != 1)
  {
    current = current->next;
    // Verify pointer
    if(current != NULL)
    {
      fprintf(stderr, "Structure out of bounds!.\n");
      exit(1);
    }
  }
  // Allocate new structre
  temp = allocate();
  // Fill the new structure
  temp->id = 5;
  strcpy(temp->name, "apricots");
  temp->price = 1.36;
  // Reference the following structure
  temp->next = current->next;
  // Update the current structure
  current->next = temp;
  // Output the updated list
  output(first);
  
  return(0);
}