#include <bits/stdc++.h>
using namespace std;
#define MAX 5

/*
Problem with Simple Queue:
    Let's Enqueue 1 5 9 in a Queue
    | 1 | 5 | 9 | -> front = 0; rear = 2
    Now dequeue the above Queue
    | 5 | 9 | means front=1; rear=2
    Again dequeue
    | 9 | means front = 2; rear = 2
    Now running isFull() returns true because rear=sizeof(arr)-1 and we can not add new values at previous pointers
Solution in Circular Queue:
    a little change in isFull(), enqueue() and dequeue() of linear queue
        enqueue(): instead of doing rear++, we do rear = (rear+1)%sizeofQueue
        dequeue(): instead of doing front++; we do front = (front+1)%sizeofQueue
        isFull(): chech for if((rear+1)%size==front)

*/

class CircularQueue
{
private:
    int front;     // removed from front end
    int rear;      // added from rear end
    int arr[MAX];  // size of array
    int itemCount; // keeps track of items in the queue

public:
    // constructor
    CircularQueue()
    {
        itemCount = 0; // initialise items to 0
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
        {                                                      // when queue is neither full nor empty
            rear = ((rear + 1) % (sizeof(arr) / sizeof(int))); // increase rear to next position in circular manner
            arr[rear] = value;                                 // set value to current rear index in queue
        }
        itemCount++; // increase item count
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
            itemCount--; // decrease item count
            return v;
        }
        else
        {                                                        // when we have multiple values in queue
            v = arr[front];                                      // store value of last element in a variable
            arr[front] = 0;                                      // remove value at arr[front] and set to 0
            front = ((front + 1) % (sizeof(arr) / sizeof(int))); // set front to next value
            itemCount--;                                         // decrease item count
            return v;
        }
    }

    // check if queue is full
    bool isFull()
    {
        if ((rear + 1) % (sizeof(arr) / sizeof(int)) == front) // being pointer starting from -1; it would be 1 less than the array index (sizeof(arr)-1)
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
        return itemCount;
    }

    // display all elements of queue
    void display()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << "  ";
        }
    }
};

int main()
{
    CircularQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "\nisFull:" << q.isFull();
    cout << "\nCount: " << q.count();

    cout << q.dequeue();
    q.enqueue(8);  // appends to index[0]

    cout << "\nCount: " << q.count() << endl;

    q.display();
    return 0;
}
