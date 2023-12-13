/*
Quick Sort Algorithm (Divide and Conquer)

        Sorts an array by recursively dividing it into two sub-arrays,
        one containing elements less than a chosen pivot element,
        and the other containing elements greater than or equal to the pivot.
        This process repeats until each sub-array contains only one element (sorted).

Time Complexity: O(n log n) on average, O(n^2) in worst case.

Algorithm:
        > Select a pivot element from the array (e.g., middle element).
        > Partition the array into two sub-arrays:
        > Left: elements less than the pivot.
        > Right: elements greater than or equal to the pivot.
        > Recursively apply Quick Sort to both left and right sub-arrays.
        > Merge the sorted left and right sub-arrays back into the original array.

Output Parameters:
        [In] size of the array[n]
        [In] pointer to the array of elements[arr]
        [Op] sorted array
*/

#include <iostream>
using namespace std;

// swap two elements
inline void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// Partition function to rearrange elements around a pivot
int partition(int arr[], int low, int high) {

  // Choose the last element as the pivot
  int pivot = arr[high];
  int i = (low - 1); // index of smaller element

  // Place elements smaller than pivot to the left of i
  for (int j = low; j <= high - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  // Place pivot element at its correct position
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

// Recursive quick sort function
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    // pi is partitioning index
    int pi = partition(arr, low, high);

    // Recursively sort elements before and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Print the sorted array
void printArray(int arr[], int size) {
  cout << "Sorted array: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  // Example unsorted array
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Sort the array using quick sort
  quickSort(arr, 0, n - 1);

  // Print the sorted array
  printArray(arr, n);

  return 0;
}