#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node
{
  int data;
  struct Node *next;
};

// Function to push an element to the stack
void push(struct Node **top, int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (!newNode)
  {
    printf("Stack Overflow\n");
    return;
  }
  newNode->data = data;
  newNode->next = *top;
  *top = newNode;
  printf("%d pushed to stack\n", data);
}

// Function to check if the stack is empty
int isEmpty(struct Node *top)
{
  return !top;
}

// Function to pop an element from the stack
int pop(struct Node **top)
{
  if (isEmpty(*top))
  {
    printf("Stack Underflow\n");
    return -1;
  }
  struct Node *temp = *top;
  int popped = temp->data;
  *top = temp->next;
  free(temp);
  return popped;
}

// Function to peek at the top element of the stack
int peek(struct Node *top)
{
  if (isEmpty(top))
  {
    printf("Stack is empty\n");
    return -1;
  }
  return top->data;
}

// Function to display the stack
void display(struct Node *top)
{
  if (isEmpty(top))
  {
    printf("Stack is empty\n");
    return;
  }
  struct Node *temp = top;
  printf("Stack elements: ");
  while (temp)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// Main function
int main()
{
  struct Node *top = NULL;
  int choice, data;

  while (1)
  {
    printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the data to push: ");
      scanf("%d", &data);
      push(&top, data);
      break;
    case 2:
      printf("Popped element: %d\n", pop(&top));
      break;
    case 3:
      printf("Top element: %d\n", peek(top));
      break;
    case 4:
      display(top);
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid choice, try again.\n");
    }
  }
  return 0;
}
