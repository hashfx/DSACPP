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
