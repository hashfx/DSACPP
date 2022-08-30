/*
Linear Search:
    Method of finding an element within a list
    Sequentially checks each element of the list until a match is found or the whole list has been searched
Output Param:
    [In] size of array[n]
    [In] elements of array[n]
    [In] key value to be searched in array[n] 
    [Op] Key Index || -1
*/

#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
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

    cout << linearSearch(arr, n, key) << endl;
    return 0;
}