#include <stdio.h>
#include <stdlib.h>

struct node *add_to_list(struct node *list, int n);
struct node *read_numbers(vodi);

int main(void)
{
  struct node
  {
    int value; // Data stored in the node
    struct node *next; //Pointer to the next node
  };
  struct node *first = NULL; // To later point to the first node in the list
  struct node *new_node; // Variable that points to the node temporarily, until inserted 
  new_node = (struct node *)malloc(sizeof(struct node)); // Allocation of memory for new node
  new_node->value = 10;
  new_node->next = first;
  first = new_node;
  // Repeat for next node with different value
  new_node = (struct node *)malloc(sizeof(struct node)); // Allocation of memory for new node
  new_node->value = 20;
  new_node->next = first;
  first = new_node;
  
  first = add_to_list(first, 10);
  first = add_to_list(first, 20);
  
  puts("Simple linked-list example TEST");
  
  return(0);
}

struct node *add_to_list(struct node *list, int n)
{
  struct node *new_node;
  new_node = (struct node *)malloc(sizeof(struct node));
  if(new_node == NULL)
  {
    printf("ERROR: malloc failed in FUNCTION -> add_to_list()\n");
    exit(EXIT_FAILURE);
  }
  new_node->value = n;
  new_node->next = list;
  return new_node;
}

struct node *read_numbers(void)
{
  struct node *first = NULL;
  int n;
  printf("Please enter a series of integers (0 to terminate): ");
  
  for(;;)
  {
    scanf("%d", &n);
  
    if(n == 0)
      return first;
    first = add_to_list(first, n);
  }
}