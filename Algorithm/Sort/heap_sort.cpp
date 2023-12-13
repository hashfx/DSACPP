/*
Heap Sort:
    comparison-based sorting algorithm, uses a binary heap data structure
    works by building a max heap and repeatedly extracting the maximum element

Algorithm:
Build a max heap:
    a. start from the last non-leaf node and heapify each node until the root.
    b. heapify: Compare the root with its left and right children, swap if needed, and recursively heapify.
4. Extract elements from the heap:
    a. swap the root (maximum element) with the last element.
    b. reduce the heap size and heapify the root.
    c. repeat until the heap is empty.
    
Output Parameters:
    [In] size of array [n]
    [In] elements of array [arr]
    [Op] sorted array
*/

#include <iostream>
using namespace std;

// function to heapify a subtree rooted at the given index
void heapify(int arr[], int n, int i) {
    int largest = i;    // assume the current node is the largest
    int left_child = 2 * i + 1;  // left child index
    int right_child = 2 * i + 2;  // right child index

    // check if left child is larger than the current largest node
    if (left_child < n && arr[left_child] > arr[largest])
        largest = left_child;

    // check if right child is larger than the current largest node
    if (right_child < n && arr[right_child] > arr[largest])
        largest = right_child;

    // if the largest node is not the current node, swap them and recursively heapify
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// function to perform heap sort on the given array
void heap_sort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // swap the root with the last element
        swap(arr[0], arr[i]);
        // heapify the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;  // input size of the array

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // input array elements
    }

    // Perform heap sort
    heap_sort(arr, n);

    // display the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
