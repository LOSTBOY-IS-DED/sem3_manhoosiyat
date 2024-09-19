#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node
{
  int data;
  struct Node *next;
};

// Function to enqueue an element to the queue
void enqueue(struct Node **front, struct Node **rear, int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (!newNode)
  {
    printf("Queue Overflow\n");
    return;
  }
  newNode->data = data;
  newNode->next = NULL;

  if (*rear == NULL)
  {
    *front = *rear = newNode;
    printf("%d enqueued to queue\n", data);
    return;
  }
  (*rear)->next = newNode;
  *rear = newNode;
  printf("%d enqueued to queue\n", data);
}

// Function to check if the queue is empty
int isEmpty(struct Node *front)
{
  return !front;
}

// Function to dequeue an element from the queue
int dequeue(struct Node **front)
{
  if (isEmpty(*front))
  {
    printf("Queue Underflow\n");
    return -1;
  }
  struct Node *temp = *front;
  int dequeued = temp->data;
  *front = (*front)->next;

  free(temp);
  return dequeued;
}

// Function to display the queue
void display(struct Node *front)
{
  if (isEmpty(front))
  {
    printf("Queue is empty\n");
    return;
  }
  struct Node *temp = front;
  printf("Queue elements: ");
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
  struct Node *front = NULL;
  struct Node *rear = NULL;
  int choice, data;

  while (1)
  {
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the data to enqueue: ");
      scanf("%d", &data);
      enqueue(&front, &rear, data);
      break;
    case 2:
      printf("Dequeued element: %d\n", dequeue(&front));
      break;
    case 3:
      display(front);
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice, try again.\n");
    }
  }
  return 0;
}
