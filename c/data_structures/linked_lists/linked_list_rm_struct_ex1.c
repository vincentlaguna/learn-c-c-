#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16
// Define structure externally
struct item
{
  int id;
  char name[SIZE];
  float price;
  struct item *next;
};
// Allocate new structure
struct item *allocate(void)
{
  struct item *p;
  p = (struct item *)malloc(sizeof(struct item) * 1);
  // Verify memory allocation
  if(p == NULL)
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
    printf("%d: %s for $%.2f/pound\n",
            s->id,
            s->name,
            s->price);
    s = s->next;
  }
  putchar('\n');
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
  puts("\nOriginal List -> \n");
  output(first);
  // Remove the fourth structure from the list
  puts("\nRemoving the fourth record...\n");
  current = first;
  // Locate the third structure to remove the fourth
  while(current->id != 2) // Change to 3 to remove the final structure
  {
    current = current->next;
    // Always test with pointers!
    if(current == NULL)
    {
      fprintf(stderr, "Structure out of bounds!.\n");
      exit(1);
    }
  }
  // Save the current->next pointer
  temp = current->next;
  // Refocus the next pointer to reference struct 4 instead of 3
  current->next = temp->next;
  // Free the storage!
  free(temp);
  // Output the updated list
  output(first);
  
  return(0);
}