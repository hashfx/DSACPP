/*
The smallest element is selected from the unsorted array and swapped with the leftmost element, and that element becomes a part of the sorted array. This process continues moving unsorted array boundary by one element to the right.

'rem'
    Find the minimum element in unsorted array and swap it with element at beginning
Output Param:
    [In] size of array[n]
    [In] elements of array[n]
    [Op] sorted array


*/

#include <iostream>
using namespace std;
int main()
{
    int n; // size of array
    cin >> n;

    int arr[n]; // initialise array of size n

    // input array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // selection sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                // swap to current element
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    // display sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}