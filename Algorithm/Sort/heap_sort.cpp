/*
Heap Sort:
    comparison-based sorting algorithm, uses a binary heap data structure
    builds a max heap, iteratively extracts maximum element

Algorithm:
    build a max heap:
        start from last non-leaf node and heapify each node until root
            - for each node, compare with its left and right children, swap if necessary
            - move to next node until the entire heap is built
    extract elements from the heap:
        swap root (maximum element) with last element
        reduce heap size and heapify root
        repeat until heap is empty

    
output parameters:
    [In] size of array [n]
    [In] elements of array [arr]
    [Op] sorted array
*/


#include <iostream>
using namespace std;

// function to heapify a subtree rooted at the given index
void heapify(int arr[], int n, int i) {
    while (true) {
        int largest = i;  // assume the current node is the largest
        int left_child = 2 * i + 1;  // left child index
        int right_child = 2 * i + 2;  // right child index

        // check if left child is larger than the current largest node
        if (left_child < n && arr[left_child] > arr[largest])
            largest = left_child;

        // check if right child is larger than the current largest node
        if (right_child < n && arr[right_child] > arr[largest])
            largest = right_child;

        // if the largest node is not the current node, swap them
        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest;  // move to the larger child to continue heapifying
        } else {
            break;  // if the heap property is satisfied, exit the loop
        }
    }
}

// function to perform heap sort on the given array
void heap_sort(int arr[], int n) {
    // build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // swap the root with the last element
        swap(arr[0], arr[i]);

        // heapify the reduced heap starting from the root
        int current = 0;
        while (true) {
            int largest = current;
            int left_child = 2 * current + 1;
            int right_child = 2 * current + 2;

            if (left_child < i && arr[left_child] > arr[largest])
                largest = left_child;

            if (right_child < i && arr[right_child] > arr[largest])
                largest = right_child;

            if (largest != current) {
                swap(arr[current], arr[largest]);
                current = largest;
            } else {
                break;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;  // input size of the array

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // input array elements
    }

    // perform heap sort
    heap_sort(arr, n);

    // display the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
