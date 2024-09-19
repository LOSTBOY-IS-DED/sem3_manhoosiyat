// single linked list --> insertion and deletion

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
  int data;
  struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (!newNode)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the list
void insert_at_beg(struct Node **head, int data)
{
  struct Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

// Function to insert a node at the end of the list
void insert_at_end(struct Node **head, int data)
{
  struct Node *newNode = createNode(data);
  if (*head == NULL)
  {
    *head = newNode;
    return;
  }
  struct Node *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

// Function to insert a node at a specific position
void insert_at_pos(struct Node **head, int data, int pos)
{
  struct Node *newNode = createNode(data);
  if (pos == 1)
  {
    newNode->next = *head;
    *head = newNode;
    return;
  }

  struct Node *temp = *head;
  for (int i = 1; temp != NULL && i < pos - 1; i++)
  {
    temp = temp->next;
  }
  if (temp == NULL)
  {
    printf("Position out of range\n");
    return;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

// Function to delete a node from the beginning of the list
void del_from_beg(struct Node **head)
{
  if (*head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  struct Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

// Function to delete a node from the end of the list
void del_from_end(struct Node **head)
{
  if (*head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  struct Node *temp = *head;
  if (temp->next == NULL)
  {
    free(temp);
    *head = NULL;
    return;
  }

  struct Node *prev = NULL;
  while (temp->next != NULL)
  {
    prev = temp;
    temp = temp->next;
  }
  prev->next = NULL;
  free(temp);
}

// Function to delete a node from a specific position
void del_at_pos(struct Node **head, int pos)
{
  if (*head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  struct Node *temp = *head;

  if (pos == 1)
  {
    *head = temp->next;
    free(temp);
    return;
  }

  struct Node *prev = NULL;
  for (int i = 1; temp != NULL && i < pos; i++)
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
  {
    printf("Position out of range\n");
    return;
  }

  prev->next = temp->next;
  free(temp);
}

// Function to display the linked list
void display(struct Node *head)
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// Main function with menu-driven options
int main()
{
  struct Node *head = NULL;
  int choice, data, pos;

  while (1)
  {
    printf("\nMenu:\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at position\n");
    printf("4. Delete from beginning\n");
    printf("5. Delete from end\n");
    printf("6. Delete from position\n");
    printf("7. Display list\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter data to insert at beginning: ");
      scanf("%d", &data);
      insert_at_beg(&head, data);
      break;

    case 2:
      printf("Enter data to insert at end: ");
      scanf("%d", &data);
      insert_at_end(&head, data);
      break;

    case 3:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      printf("Enter position: ");
      scanf("%d", &pos);
      insert_at_pos(&head, data, pos);
      break;

    case 4:
      del_from_beg(&head);
      break;

    case 5:
      del_from_end(&head);
      break;

    case 6:
      printf("Enter position to delete: ");
      scanf("%d", &pos);
      del_at_pos(&head, pos);
      break;

    case 7:
      display(head);
      break;

    case 8:
      exit(0);

    default:
      printf("Invalid choice, please try again.\n");
    }
  }

  return 0;
}
