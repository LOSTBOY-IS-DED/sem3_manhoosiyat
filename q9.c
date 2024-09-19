// sorting algorithms

#include <stdio.h>
#define MAX_SIZE 100

int arr[MAX_SIZE];
int size;

// Function to print the array
void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Bubble Sort function
void bubbleSort()
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Insertion Sort function
void insertionSort()
{
  for (int i = 1; i < size; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

// Selection Sort function
void selectionSort()
{
  for (int i = 0; i < size - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }
    if (minIndex != i)
    {
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}

// Merge function for Merge Sort
void merge(int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k++] = L[i++];
    }
    else
    {
      arr[k++] = R[j++];
    }
  }

  while (i < n1)
  {
    arr[k++] = L[i++];
  }

  while (j < n2)
  {
    arr[k++] = R[j++];
  }
}

// Merge Sort function
void mergeSort(int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;

    mergeSort(l, m);
    mergeSort(m + 1, r);

    merge(l, m, r);
  }
}

// Partition function for Quick Sort
int partition(int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  return (i + 1);
}

// Quick Sort function
void quickSort(int low, int high)
{
  if (low < high)
  {
    int pi = partition(low, high);

    quickSort(low, pi - 1);
    quickSort(pi + 1, high);
  }
}

// Main function
int main()
{
  int choice;

  do
  {
    printf("\nMenu:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice != 6)
    {
      printf("Enter the number of elements: ");
      scanf("%d", &size);

      if (size > MAX_SIZE)
      {
        printf("Size exceeds maximum allowed size of %d\n", MAX_SIZE);
        continue;
      }

      printf("Enter %d integers:\n", size);
      for (int i = 0; i < size; i++)
      {
        scanf("%d", &arr[i]);
      }
    }

    switch (choice)
    {
    case 1:
      bubbleSort();
      printf("Array after Bubble Sort:\n");
      printArray(arr, size);
      break;
    case 2:
      insertionSort();
      printf("Array after Insertion Sort:\n");
      printArray(arr, size);
      break;
    case 3:
      selectionSort();
      printf("Array after Selection Sort:\n");
      printArray(arr, size);
      break;
    case 4:
      mergeSort(0, size - 1);
      printf("Array after Merge Sort:\n");
      printArray(arr, size);
      break;
    case 5:
      quickSort(0, size - 1);
      printf("Array after Quick Sort:\n");
      printArray(arr, size);
      break;
    case 6:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 6);

  return 0;
}
