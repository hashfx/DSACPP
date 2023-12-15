/*
Divide and Conquer Algorithm: Divides input array in two halves, calls itself
for two halves recursively and then merges the two sorted halves Time Complexity
O(nlog(n))

Algorithm:
  > Find middle point to divide the array into 2 halves
  > Call Merge Sort for first half
  > Call Merge Sort for second half
  > Merge 2 halves sorted into above 2 steps

Output Param:
        [In] size of array[n]
        [In] elements of array[n]
        [Op] sorted array

*/
#include <iostream>
using namespace std;

// merge divided sub-arrays
void merge(int arr[], int leftArray, int midPoint, int rightArray) {
  /*
  Algorithm
    > init variables (i, j, k...) to keep track of index of sub arrays and
  temporary merged array > compare values of indices and add smaller value to
  temporary array > increment index for subarray
    >
  */
  // init pointers to keep track of sub array indices
  int i = leftArray;    // starting index for left sub array
  int j = midPoint + 1; // starting index for right sub array
  int k = leftArray;    // starting index for temporary sub array

  // temporary array
  int size = (rightArray - 1) + 1;
  int temp[size];

  // keep iteration bounded by index
  // i iterate from leftmost index to mid point of left sub array
  // j iterate from midPoint+1 index to rightmost index of right sub array
  while (i <= midPoint && j <= rightArray) {
    // element in left sub array < element in right sub array
    if (arr[i] < arr[j]) {
      temp[k] = arr[i]; // insert smaller element to temporary array
      i++;              // increase index of left sub array
      k++;              // increase index of temporary array
    } else { // element in right sub array < element in left sub array
      temp[k] = arr[j];
      j++; // increase index of right sub array
      k++;
    }
  }
  while (i <= midPoint) {
    temp[k] = arr[i];
    i++;
    k++;
  }
  while (j <= rightArray) {
    temp[k] = arr[j];
    j++;
    k++;
  }
  for (int c = leftArray; c <= rightArray; c++) {
    arr[c] = temp[c];
  }
}
// merge sort function
void mergeSort(int arr[], int leftArray, int rightArray) {
  // smaller sub array has only one element or not
  // if true, would stop mergeSort()
  if (leftArray < rightArray) { // base condition
    int midPoint = (leftArray + rightArray) / 2;

    // calling mergeSort() for left sub array
    mergeSort(arr, leftArray, midPoint);

    // calling mergeSort() for right sub array
    mergeSort(arr, midPoint + 1, rightArray);

    // merge divided arrays
    merge(arr, leftArray, midPoint, rightArray);
  }
}

int main() {

  // size of array
  int n;
  cin >> n;

  // initialise array of size n
  int input_arr[n];

  // take array input from user
  for (int i = 0; i < n; i++) {
    cin >> input_arr[i];
  }

  // call mergeSort() on input_array
  mergeSort(input_arr, 0, (n - 1));

  // output array with sorted elements
  for (int i = 0; i < n; i++) {
    cout << input_arr[i] << " ";
  }
  return 0;
}
