#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    
    return 0;
}