/*
Bubble Sort Optimized:
    - checks whether the array is sorted or not after each iteration
    - helps in achieving efficiency by reducing number of iterations if the list
is already sorted
    - var flag is true if elements after iteration has to be swapped
    - flag is false initially; in each iteration, flag turns to true
    - in case no iteration occurs, flag is set to false
    - if flag is false after iteration, main loop is broken
*/
#include <iostream>
using namespace std;

void BubbleSort(int a[]) {
  int iter = 0; // initial iteration: 0
  int size;

  for (int i = 0; i < size; i++) {
    iter++; // increase number of iterations
    int flag = false;
    for (int j = 0; j < (size - i - 1); j++) {
      if (a[j] > a[j + 1]) {
        flag = true;
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
    if (flag == false) {
      break;
    }
  }
  cout << "No of iterations : " << iter << endl;
}

int main() {
  int size;
  cout << "Input size: ";
  cin >> size;
  int arr[size];
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }
  BubbleSort(arr);
  return 0;
}