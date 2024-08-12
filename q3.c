#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char queue[MAX];
int front = -1, rear = -1;

// Function to insert an element into the queue
void ENQUE(char value)
{
  if (rear == MAX - 1)
  {
    printf("Queue Overflow\n");
  }
  else
  {
    if (front == -1)
    {
      front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("%c enqueued into the queue.\n", value);
  }
}

// Function to delete an element from the queue
char DELQUE()
{
  if (front == -1 || front > rear)
  {
    printf("Queue Underflow\n");
    return '\0';
  }
  else
  {
    char dequeuedValue = queue[front];
    front++;
    printf("%c dequeued from the queue.\n", dequeuedValue);
    if (front > rear)
    {
      front = rear = -1; // Reset the queue if it's empty
    }
    return dequeuedValue;
  }
}

// Function to display all elements of the queue
void DISPLAY()
{
  if (front == -1)
  {
    printf("Queue is empty.\n");
  }
  else
  {
    printf("Queue elements are:\n");
    for (int i = front; i <= rear; i++)
    {
      printf("%c\n", queue[i]);
    }
  }
}

int main()
{
  int choice;
  char value;

  while (1)
  {
    printf("\nMenu:\n");
    printf("1. ENQUE\n");
    printf("2. DELQUE\n");
    printf("3. DISPLAY\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the character to enqueue: ");
      scanf(" %c", &value);
      ENQUE(value);
      break;
    case 2:
      DELQUE();
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
