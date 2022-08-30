#include <bits/stdc++.h>
using namespace std;
#define MAX 10

class Stack
{
private:
    int top;      // position of latest elements in stack
    int arr[MAX]; // size of array

public:
    Stack() // constructor
    {
        top = -1; // points to top of the Stack :: -1:stack is empty
        for (int i = 0; i < sizeof(arr); i++)
        {
            arr[i] = 0; // set all values to zero
        }
    }

    // stack is empty or not
    bool isEmpty()
    {
        if (top == -1) // stack is empty
            return true;
        else
            return false;
    }

    // stack is full or not
    bool isFull()
    {
        if (top == (MAX - 1))
            return true;
        else
            return false;
    }

    // insert element into stack; if space is !available, stack is in StackOverFlow state
    void push(int value)
    {
        // check whether Stack is full or not
        if (isFull())
        {
            cout << "Stack OverFlow" << endl;
        }
        else
        {
            // push value
            top++;            // increase top pointer to store value at next block
            arr[top] = value; // set value to arr[top] index
        }
    }

    // return itm at top of stack and removes it; if pop an empty stack, stack is in StackUnderFlow state
    int pop()
    {
        // check whether Stacj is empty or not
        if (isEmpty())
        {
            cout << "Stack UnderFlow" << endl;
        }
        else
        {
            // display value of top of the Stack
            int popped = arr[top]; // store current value in var popped
            arr[top] = 0;          // set value of arr[top] to 0
            top--;                 // decrease top to point at lower block value
            return popped;         // return popped value
        }
        return 0;
    }

    // access the element at (i)th position
    void peek() {}

    // number of elements in stack
    void count() {}

    // change element at (i)th position
    void change() {}

    // display al elements in stack
    void display()
    {
        // iterate Stack to render all values
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Stack s; // object of Stack
    s.push(5);
    s.push(10);
    s.pop(); // 1644
    s.display();

    return 0;
}