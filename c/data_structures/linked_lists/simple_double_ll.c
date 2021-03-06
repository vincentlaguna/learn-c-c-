#include <stdio.h>
#include <stdlib.h>
// Self-referential structure
typedef struct node
{
  char data;
  struct node *pNext;
} node_t;
// Initialize struct pointer
typedef node_t *pListNode;
// Prototypes
void insert(pListNode *head, char value);
void insertAtStart(pListNode *head, char value);
void insertAtEnd(pListNode *head, char value);
char delete(pListNode *head, char value);
void deleteAtStart(pListNode *head);
int isEmtpy(pListNode head);
void printList(pListNode pCurrent);
// Main functions
int main(void)
{
  puts("This is a linked list project - TEST");
  pListNode head = NULL; // Because initially there no nodes
  int choice = 0; // User's choice
  char item = '\0'; // Item entered by the user
  // Display the menu
  printf("Please enter your choice:\n"
         "1. To insert an item into the list in alphabetical order.\n"
         "2. To insert an element at the end of the list.\n"
         "3. To insert an item at the beginning of the list.\n"
         "4. To delete an item from the list.\n"
         "5. To delete an item from the beginning of the list.\n"
         "6. To END.\n");
  printf(":: ");
  scanf("%d", &choice);
  // While loop while user does not choose
  while(choice != 6)
  {
    switch(choice)
    {
      case 1:
        printf("Enter a character: ");
        scanf("\n%c", &item);
        insert(&head, item); // Insert the item into the list
        printList(head);
        break;
        
      case 2:
        printf("Enter a character: ");
        scanf("\n%c", &item);
        insertAtEnd(&head, item); // Insert the item into the list
        printList(head);
        break;
        
      case 3:
        printf("Enter a character: ");
        scanf("\n%c", &item);
        insertAtStart(&head, item);
        printList(head);
        break;
        
      case 4: // Delete an element
        if(!isEmtpy(head)) // If the list is not empty
        {
          printf("Enter character to be deleted: ");
          scanf("\n%c", &item);
          // If the character is found, remove it
          if(delete(&head, item)) // Remove item
          {
            printf("%c deleted.\n", item);
            printList(head);
          }
          else // End if
          {
            printf("%c not found.\n\n", item);
          } // End else
        }
        else // End if
        {
          printf("The list is empty.\n\n");
        } // End else
        break;
      
      case 5: // Delete an element at the beginning
        if(!isEmtpy(head)) // If the list is not empty
        {
          deleteAtStart(&head); // If character is found, remove it
          printf("%c deleted.\n", item);
          printList(head);
        } // End if
        else
        {
          printf("The list is empty.\n\n");
        } // End else
        break;
      
      default:
        printf("Invalid choice.\n\n");
        // Display the menu
        printf("Enter your choice:\n"
               "1. To inset an element into the list.\n"
               "2. To delete an element from the list.\n"
               "3. To End.\n");
        break;
    } // End switch
    printf("? ");
    scanf("%d", &choice);
  } // End while-loop
  printf("End of run.\n");
  // Indicate successful termination of the program
  return(0);
}
// Function Definitions
void insertAtStart(pListNode *head, char value)
{
  pListNode new_node = malloc(sizeof(node_t));
  new_node->data = value;
  new_node->pNext = *head;
  *head = new_node;
}

void insertAtEnd(pListNode *head, char value)
{
  pListNode pCurrent = *head;
  // If the current pointer is not at the end of the list (NULL)
  if(pCurrent != NULL)
  {
    while(pCurrent->pNext != NULL)
    {
      pCurrent = pCurrent->pNext;
    } // Now we can add a new variable
    pCurrent->pNext = malloc(sizeof(node_t));
    pCurrent->pNext->data = value;
    pCurrent->pNext->pNext = NULL;
  }
  else  // We are at the end of the list (pCurrent reached the end NULL pointer)
  {
    pCurrent = malloc(sizeof(node_t));
    pCurrent->data = value;
    pCurrent->pNext = NULL;
    *head = pCurrent;
  }
}

void insert(pListNode *head, char value)
{
  pListNode pNew; // Pointer to the new node
  pListNode pPrevious; // Pointer to the previous pointer in the list
  pListNode pCurrent; // Pointer to the current pointer in the list
  // Allocate memory to the new node pointer
  pNew = malloc(sizeof(node_t)); // Creation of node
  if(pNew != NULL) // Is space available?
  {
    pNew->data = value; // Place the value in the node
    pNew->pNext = NULL; // Node does not link to another node
    // Initialize the pointers
    pPrevious = NULL;
    pCurrent = *head;
    // Loop to find the correct location on the list
    while(pCurrent != NULL && value > pCurrent->data)
    {
      pPrevious = pCurrent; // Walk to...
      pCurrent = pCurrent->pNext; // ...The next node in the list
    } // End the while loop
    // Insert the new node at the beginning of the list
    if(pPrevious == NULL)
    {
      pNew->pNext = *head;
      *head = pNew;
    } // End if
    else // Insert new node between pPrevious and pCurrent pointer
    {
      pPrevious->pNext = pNew;
      pNew->pNext = pCurrent;
    } // End else
  } // End if
  else
  {
    printf("%c not inserted. No memory available.\n", value);  
  }
}

void deleteAtStart(pListNode *head)
{
  pListNode pTemp = NULL; // Temporary node pointer
  // Check for NULL first
  if(head == NULL)
  {
    return;
  }
  else
  {
    pTemp = *head; // Hold onto the node being removed
    *head = (*head)->pNext; // De-thread the node
    free(pTemp); // Free the de-threaded node
  }
}

char delete(pListNode *head, char value)
{
  pListNode pPrevious; // Pointer to the previous node in the list
  pListNode pCurrent; // Pointer to the current node in the list
  pListNode pTemp; // Temporary node pointer
  // Delete the first node
  if(value == (*head)->data)
  {
    pTemp = *head; // Hold onto the node being removed
    *head = (*head)->pNext; // De-thread the node
    free(pTemp); // Free the de-threaded node
    return value;
  } // End if
  else
  {
    pPrevious = *head;
    pCurrent = (*head)->pNext;
    // Loop to find the correct location on the list
    while(pCurrent != NULL && pCurrent->data != value)
    {
      pPrevious = pCurrent; // Walk to...
      pCurrent = pCurrent->pNext; // ...The next node in the list
    } // End of the while-loop
    // Found it, delete node at pCurrent pointer
    if(pCurrent != NULL)
    {
      pTemp = pCurrent;
      pPrevious->pNext = pCurrent->pNext;
      free(pTemp);
      return value;
    } // End if
  } // End else
  // Not found
  return '\0';
} // End function delete function
// Return 1 if the list is empty, 0 if otherwise
void printList(pListNode pCurrent)
{
  // Check for empty list
  if(pCurrent == NULL)
  {
    printf("The list is empty.\n\n");
  } // End if
  else
  {
    printf("The list is:\n");
    // While not the end of the list
    while(pCurrent != NULL)
    {
      printf("%c --> ", pCurrent->data);
      pCurrent = pCurrent->pNext;
    } // End of the while-loop
    printf("NULL\n\n");
  } // End else
} // End of the function printList()

int isEmtpy(pListNode head)
{
  return head == NULL;
} // End function isEmpty()