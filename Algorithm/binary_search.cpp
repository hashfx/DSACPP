/*
Binary Search:
    Search Algorithm that finds the position of a target value within a sorted array(ASCE). Binary search compares the target value to the middle element of the array.
Output Param:
    [In] size of array[n]
    [In] elements of array[n]
    [In] key value to be searched in array[n] 
    [Op] Key Index || -1

*/
#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{

    int s = 0; // Starting Point
    int e = n; // Ending Point
    
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
            
    }
    return -1;

}    
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;

    cout << binarySearch(arr, n, key);
    
    return 0;
}