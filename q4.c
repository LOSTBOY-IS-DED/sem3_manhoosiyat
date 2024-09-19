// write a menu driven C program to implement circular queue operation using array
// 1. insert an element in the circular queue
// 2. delete an element in the circular queue
// 3. display element of the circular queue

#include <stdio.h>

#define MAX_SIZE 3
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void insert(int item)
{
  if ((rear + 1) % MAX_SIZE == front)
  {
    printf("Queue is full\n");
  }
  else
  {
    if (front == -1)
    { // If queue is empty
      front = rear = 0;
    }
    else
    {
      rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = item;
    printf("Item inserted: %d\n", item);
  }
}

void delete()
{
  if (front == -1)
  { // Queue is empty
    printf("Queue is empty\n");
  }
  else
  {
    int item = queue[front];
    if (front == rear)
    {
      // Queue has only one element
      front = rear = -1;
    }
    else
    {
      front = (front + 1) % MAX_SIZE;
    }
    printf("Item deleted: %d\n", item);
  }
}

void display()
{
  if (front == -1)
  {
    printf("Queue is empty\n");
  }
  else
  {
    printf("The elements of the queue are:\n");

    int i = front;
    // Loop runs until we've wrapped back around to front in the circular queue
    while (i != rear)
    {
      printf("%d ", queue[i]);
      i = (i + 1) % MAX_SIZE;
    }
    // Print the last element at rear
    printf("%d\n", queue[rear]);
  }
}

int main()
{
  int choice, item;
  printf("1. Insert\n2. Delete\n3. Display\n");
  while (1)
  {
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the item to be inserted: ");
      scanf("%d", &item);
      insert(item);
      break;
    case 2:
      delete ();
      break;
    case 3:
      display();
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}
