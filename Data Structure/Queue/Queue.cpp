#include <bits/stdc++.h>
using namespace std;
#define MAX 5
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
    void enqueue(int value)
    {
        if (isFull()) // check if queue is full
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (isEmpty())
        {
            // pointers need to have at same position if empty [-1 + 1 = 0 index]
            rear = 0;          // rear pointing to entry
            front = 0;         // front pointing to exit
            arr[rear] = value; // set rear to value
        }
        else
        {                      // when queue is neither full nor empty
            rear++;            // increase rear to next position
            arr[rear] = value; // set value to current rear index in queue
        }
    }

    // elements are removed from front end
    int dequeue()
    {
        int v;
        // if Queue is Empty, it can't be dequeued
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        else if (front == rear)
        {                   // if queue have only one element
            v = arr[front]; // store value of last element in a variable
            arr[front] = 0; // remove value at arr[front] and set to 0
            // set pointers back to -1
            rear = -1;
            front = -1;
            return v;
        }
        else
        {                   // when we have multiple values in queue
            v = arr[front]; // store value of last element in a variable
            arr[front] = 0; // remove value at arr[front] and set to 0
            front++;        // set front to next value
            return v;
        }
    }

    // check if queue is full
    bool isFull()
    {
        if (rear == (sizeof(arr)/sizeof(int)) - 1) // being pointer starting from -1; it would be 1 less than the array index (sizeof(arr)-1)
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
    int count()
    {
        return (rear - front + 1);
    }
};

int main()
{
    Queue q;
    cout << q.isEmpty() << endl;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << q.count() << endl;

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.count() << endl;

    return 0;
}