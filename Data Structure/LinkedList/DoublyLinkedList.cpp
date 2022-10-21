#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *previous;
    // Node()
    // {
    //     value = 0;
    //     next = NULL;
    //     previous = NULL;
    // }
    Node(int val) // parameterized constructor
    {
        previous = NULL;
        value = val;
        next = NULL;
    }
};

class DoublyLinkedList
{
public:
    void append(Node *&head, int val)
    {
        Node *newNode = new Node(val); // create new node
        if (head == NULL)
        {
            prepend(head, val); // insert at head
            return;
        }
        Node *temp = head; // traverse through LinkedList :: temp pointer at head

        while (temp->next != NULL) // reach to last node
        {
            temp = temp->next; // traverse
        }

        // found last element, append the newly created node
        temp->next = newNode; // insert value in new node

        newNode->previous = temp; // link to previous node
        newNode->value = val;     // set value on LinkedList
        newNode->next = NULL;     // next/last node as NULL
    }

    void prepend(Node *&head, int val)
    {
        Node *newNode = new Node(val); // create a new node

        newNode->next = head;     // set next pointer to head of current node
        head->previous = newNode; // previous of current node to new node

        if (head != NULL)
        {
            head->previous = newNode; // change head pointer to new node
        }
    }

    // traverse linked list
    void display(Node *head) // head by value
    {
        // start traversing from start pointer till last element
        Node *temp = head;   // temporary pointer at Head
        while (temp != NULL) // traverse until next pointer of a node is not NULL
        {
            cout << temp->value << " "; // print value of current node
            temp = temp->next;          // shift pointer to next node
        }
        cout << endl;
    }
};

int main()
{
    Node *head = NULL;
    DoublyLinkedList dll;
    dll.append(head, 1);
    dll.append(head, 2);
    dll.append(head, 3);
    dll.append(head, 4);
    dll.append(head, 5);

    dll.display(head);

    return 0;
}