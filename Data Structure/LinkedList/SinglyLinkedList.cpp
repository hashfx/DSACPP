#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;  // value stored at linked list
    Node *next; // points to next node

    Node()
    {
        value = 0;
        next = NULL; // initially next is NULL
    }

    Node(int val)
    {
        value = val;
        next = NULL; // initially next is NULL
    }

    // insert a new node at specific position

    // delete a node

    // update a node
};

// append new node to the end
void append(Node *&head, int val)
{
    Node *n = new Node(val); // creatitng a new node

    if (head == NULL) // if LinkedList is empty
    {
        head = n; // insert element without traversing
        return;
    }

    Node *temp = head; // traverse through LinkedList starting from head

    // iterate until reached to last node
    while (temp->next != NULL) // iterate until next pointer is not NULL
    {
        temp = temp->next; // keep shifting to next pointer
    }

    // found last element, append the newly created node
    temp->next = n; // insert value in new node
}

// prepend new node at start
void prepend(Node *&head, int val)
{
    // create a new node
    Node *n = new Node(val); // create a new node
    n->next = head;          // head stores / next points to current first node of Linked List
    head = n;                // shift head pointer to new node
}

// traverse linked list
void display(Node *head) // head by value
{
    // start traversing from start pointer till last element
    Node *temp = head;
    while (temp != NULL) // traverse until next pointer of a node is not NULL
    {
        cout << temp->value << " "; // print value of current node
        temp = temp->next;          // shift pointer to next node
    }
    cout << endl;
}

bool search(Node *head, int key)
{
    Node *temp = head;   // set a pointer `temp` at head
    while (temp != NULL) // iterate until next pointer is not NULL
    {
        if (temp->value == key) // if key is found
        {
            return true;
        }
        temp = temp->next; // move to next node
    }
    return false;
}

int main()
{
    Node *head = NULL;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    display(head);

    prepend(head, 0);
    display(head);

    cout << search(head, 5);

    return 0;
}