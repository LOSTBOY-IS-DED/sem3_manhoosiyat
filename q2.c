#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to insert an element into the stack
void PUSH(int value)
{
  if (top == MAX - 1)
  {
    printf("Stack Overflow\n");
  }
  else
  {
    top++;
    stack[top] = value;
    printf("%d pushed into the stack.\n", value);
  }
}

// Function to delete an element from the stack
int POP()
{
  if (top == -1)
  {
    printf("Stack Underflow\n");
    return -1;
  }
  else
  {
    int poppedValue = stack[top];
    top--;
    printf("%d popped from the stack.\n", poppedValue);
    return poppedValue;
  }
}

// Function to display all elements of the stack
void DISPLAY()
{
  if (top == -1)
  {
    printf("Stack is empty.\n");
  }
  else
  {
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--)
    {
      printf("%d\n", stack[i]);
    }
  }
}

int main()
{
  int choice, value;

  while (1)
  {
    printf("\nMenu:\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. DISPLAY\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the value to push: ");
      scanf("%d", &value);
      PUSH(value);
      break;
    case 2:
      POP();
      break;
    case 3:
      DISPLAY();
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}