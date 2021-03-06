#include <stdio.h>
#include <stdlib.h>

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
// Output the list
void output(struct item *s)
{
  while(s != NULL)
  {
    printf("%d: %s for $%.2f/pound\n",
            s->id + 1,
            s->name,
            s->price);
    s = s->next;
  }
}

int main(void)
{
  struct item *first, *current;
  int x;
  FILE *fp;
  // Open the file
  puts("Reading Data...");
  fp = fopen("lldata.dat", "r");
  // Verify file pointer
  if(fp == NULL)
  {
    fprintf(stderr, "Unable to open file.\n");
    exit(1);
  }
  // The list has 5 items
  for(x = 0; x < 5; x++)
  {
    if(x == 0)
    {
      // Allocate initial structure
      first = allocate();
      current = first;
    }
    else
    {
      current->next = allocate();
      // Update the pointer member, discarding the saved information
      current = current->next;
    }
    // Use fread() to fill the structure
    fread(current, sizeof(struct item), 1, fp);
  }
  // Cap the final structure
  current->next = NULL;
  // Close the file
  fclose(fp);
  // Output the list
  output(first);
  
  return(0);
}