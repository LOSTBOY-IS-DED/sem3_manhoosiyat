// Binary search and interpolation search

#include <stdio.h>

// Binary Search function
int binarySearch(int arr[], int n, int key, int *iterations)
{
  int low = 0, high = n - 1;
  *iterations = 0; // Reset iteration count

  while (low <= high)
  {
    (*iterations)++;
    int mid = (low + high) / 2;

    if (arr[mid] == key)
      return mid;
    else if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1; // Element not found
}

// Interpolation Search function
int interpolationSearch(int arr[], int n, int key, int *iterations)
{
  int low = 0, high = n - 1;
  *iterations = 0; // Reset iteration count

  while (low <= high && key >= arr[low] && key <= arr[high])
  {
    (*iterations)++;

    if (low == high)
    {
      if (arr[low] == key)
        return low;
      return -1;
    }

    // Calculate position using interpolation formula
    int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));

    if (arr[pos] == key)
      return pos;
    else if (arr[pos] < key)
      low = pos + 1;
    else
      high = pos - 1;
  }
  return -1; // Element not found
}

// Function to display the array
void displayArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int arr[100], n, key, choice;
  int binaryIterations, interpolationIterations;

  // Input array size and elements
  printf("Enter the number of elements in the sorted array: ");
  scanf("%d", &n);

  printf("Enter %d sorted elements: ", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  // Menu-driven logic
  while (1)
  {
    printf("\nMenu:\n");
    printf("1. Binary Search\n");
    printf("2. Interpolation Search\n");
    printf("3. Compare Both Searches\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 4)
    {
      printf("Exiting...\n");
      break;
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    switch (choice)
    {
    case 1:
      // Binary Search
      {
        int result = binarySearch(arr, n, key, &binaryIterations);
        if (result != -1)
          printf("Element found at index %d (Binary Search, Iterations: %d)\n", result, binaryIterations);
        else
          printf("Element not found (Binary Search, Iterations: %d)\n", binaryIterations);
      }
      break;

    case 2:
      // Interpolation Search
      {
        int result = interpolationSearch(arr, n, key, &interpolationIterations);
        if (result != -1)
          printf("Element found at index %d (Interpolation Search, Iterations: %d)\n", result, interpolationIterations);
        else
          printf("Element not found (Interpolation Search, Iterations: %d)\n", interpolationIterations);
      }
      break;

    case 3:
      // Compare both searches
      {
        int binaryResult = binarySearch(arr, n, key, &binaryIterations);
        int interpolationResult = interpolationSearch(arr, n, key, &interpolationIterations);

        printf("\nBinary Search:\n");
        if (binaryResult != -1)
          printf("Element found at index %d (Iterations: %d)\n", binaryResult, binaryIterations);
        else
          printf("Element not found (Iterations: %d)\n", binaryIterations);

        printf("\nInterpolation Search:\n");
        if (interpolationResult != -1)
          printf("Element found at index %d (Iterations: %d)\n", interpolationResult, interpolationIterations);
        else
          printf("Element not found (Iterations: %d)\n", interpolationIterations);

        // Compare number of iterations
        if (binaryIterations < interpolationIterations)
          printf("\nBinary Search is more efficient with fewer iterations.\n");
        else if (binaryIterations > interpolationIterations)
          printf("\nInterpolation Search is more efficient with fewer iterations.\n");
        else
          printf("\nBoth searches performed equally.\n");
      }
      break;

    default:
      printf("Invalid choice! Try again.\n");
    }
  }

  return 0;
}
