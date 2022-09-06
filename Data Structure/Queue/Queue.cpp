#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
class Queue
{
private:
    int front; // removed from front end
    int rear;  // added from rear end
    int arr[MAX];

public:
    // constructor
    Queue()
    {
        // initialize front and rear to -1
        front = -1;
        rear = -1;
        for (int i = 0; i < MAX; i++)
        {
            arr[i] = 0; // set values of array elements to 0
        }
    }

    // elements are added from rear end
    void enqueue() {}

    // elements are removed from front end
    void dequeue() {}

    // check if queue is full
    bool isFull()
    {
        if (rear == sizeof(arr) - 1) // being pointer starting from -1; it would be 1 less than the array index (sizeof(arr)-1)
            return true;
        else
            return false;
    }

    // check if queue is empty
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    // total items in queue
    void count() {}
};

int main()
{
    Queue q;
    cout << q.isEmpty();

    return 0;
}