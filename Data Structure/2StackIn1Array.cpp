#include <bits/stdc++.h>
using namespace std;
class twoStacks
{
    int *arr;
    int size;
    int top1, top2; // track pointers for Stack1 and Stack2
public:
    // constructor
    twoStacks(int n = 100)
    {
        size = n;
        arr = new int[n]; // array of size n
        top1 = -1;
        top2 = size;
    }
    void push1(int x)
    {
        top1++;
        arr[top1] = x;
    }
    void push2(int x)
    {
        top2--;
        arr[top2] = x;
    }
    int pop1()
    {
        if (top1 == -1) // if Stack is empty
            return -1;
        else
            return arr[top1--]; // set pointer to previous value
    }
    int pop2()
    {
        if (top2 == size)
            return -1;
        else
            return arr[top2++]; // set pointer to next value
    }
};

int main()
{
    twoStacks ts;
    ts.push1(10);
    ts.push1(20);
    ts.push1(30);
    ts.push1(40);
    ts.push2(70);
    ts.push2(80);
    ts.push2(90);
    
    cout << ts.pop1() << endl;
    cout << ts.pop1() << endl;
    cout << ts.pop1() << endl;
    cout << ts.pop1() << endl;
    cout << ts.pop2() << endl;
    cout << ts.pop2() << endl;
    cout << ts.pop2() << endl;

    return 0;
}