/*
Bubble Sort:
    simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
   *known as ~ because the maximum element comes to surface as a bubble.
Output Param:
    [In] size of array[n]
    [In] elements of array[n] 
    [Op] sorted array
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n-counter; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        counter++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}