#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// display
void display(int arr[], int size)
{
  printf("Array Elements: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// insertAtBeginning
void insertAtBeginning(int arr[], int *size, int element)
{
  if (*size >= MAX_SIZE)
  {
    printf("Array is full. Cannot insert Items.\n");
    return;
  }
  for (int i = *size; i > 0; i--)
  {
    arr[i] = arr[i - 1];
  }
  arr[0] = element;
  (*size)++;
}

// insertAtEnd
void insertAtEnd(int arr[], int *size, int element)
{
  if (*size >= MAX_SIZE)
  {
    printf("Array is full. Cannot insert Items.\n");
    return;
  }
  arr[*size] = element;
  (*size)++;
}

// insertAtPosition
void insertAtPositon(int arr[], int *size, int element, int position)
{
  if (*size >= MAX_SIZE)
  {
    printf("Array is full. Cannot insert Items.\n");
    return;
  }
  if (position < 0 || position > *size)
  {
    printf("Invalid position.\n");
    return;
  }
  for (int i = *size; i > position; i--)
  {
    arr[i] = arr[i - 1];
  }
  arr[position] = element;
  (*size)++;
}

// deleteFromBeginning
void deleteFromBeginning(int arr[], int *size)
{
  if (*size == 0)
  {
    printf("Array is empty. Cannot delete element.\n");
    return;
  }
  for (int i = 0; i < *size - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  (*size)--;
}

// deleteFromEnd
void deleteFromEnd(int arr[], int *size)
{
  if (*size == 0)
  {
    printf("Array is empty. Cannot delete element.\n");
    return;
  }
  (*size)--;
}

// deleteFromPosition
void deleteFromPosition(int arr[], int *size, int position)
{
  if (*size == 0)
  {
    printf("Array is empty. Cannot delete element.\n");
    return;
  }
  if (position < 0 || position >= *size)
  {
    printf("Invalid position.\n");
    return;
  }
  for (int i = position; i < *size - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  (*size)--;
}

// replaceElement
void replaceElement(int arr[], int *size, int position, int newElement)
{
  if (position < 0 || position >= *size)
  {
    printf("Invalid position.\n");
    return;
  }
  arr[position] = newElement;
}

// searchElement
void searchElement(int arr[], int *size, int element)
{
  for (int i = 0; i < *size; i++)
  {
    if (arr[i] == element)
    {
      printf("Element %d found at position %d.\n", element, i);
      return;
    }
  }
  printf("Element %d not found in the array.\n", element);
}

int main()
{
  int arr[MAX_SIZE];
  int size = 0;
  int choice, element, position;

  while (1)
  {
    printf("\nMenu: \n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at position\n");
    printf("4. Delete from beginning\n");
    printf("5. Delete from end\n");
    printf("6. Delete from position\n");
    printf("7. Replace Element\n");
    printf("8. Search element\n");
    printf("9. Display elements\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter element to insert at beginning: ");
      scanf("%d", &element);
      insertAtBeginning(arr, &size, element);
      break;
    case 2:
      printf("Enter element to insert at end: ");
      scanf("%d", &element);
      insertAtEnd(arr, &size, element);
      break;
    case 3:
      printf("Enter element to insert at any position: ");
      scanf("%d", &element);
      printf("Enter position to insert: ");
      scanf("%d", &position);
      insertAtPositon(arr, &size, element, position);
      break;
    case 4:
      deleteFromBeginning(arr, &size);
      break;
    case 5:
      deleteFromEnd(arr, &size);
      break;
    case 6:
      printf("Enter position to delete: ");
      scanf("%d", &position);
      deleteFromPosition(arr, &size, position);
      break;
    case 7:
      printf("Enter position to replace: ");
      scanf("%d", &position);
      printf("Enter new element: ");
      scanf("%d", &element);
      replaceElement(arr, &size, position, element);
      break;
    case 8:
      printf("Enter element to search: ");
      scanf("%d", &element);
      searchElement(arr, &size, element);
      break;
    case 9:
      display(arr, size);
      break;
    case 10:
      exit(0);
    default:
      printf("Invalid choice!\n");
    }
  }

  return 0;
}

// mistakes i faced and solved using gpt

// Error in printf statement:

// Mistake: Using single quotes for \n, making it an integer instead of a string.
// Fix: Use double quotes for \n.
// Error in replaceElement function:

// Mistake: Incorrect syntax > = instead of >=.
// Fix: Use >= for comparison.
// Error in searchElement function:

// Mistake: Comparing a pointer size with an integer.
// Fix: Use the dereferenced value *size.
// Error in main function:

// Mistake: Using insertAtPosition instead of the correct function name insertAtPositon.
// Fix: Use the correct function name.
// Error in searchElement function call:

// Mistake: Passing an integer size instead of a pointer &size.
// Fix: Pass &size as the argument.
// Error in scanf format specifier:

// Mistake: Missing % in scanf format specifier.
// Fix: Add % in scanf
