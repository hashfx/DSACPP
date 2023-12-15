#include <iostream>
using namespace std;

// custom stack implementation
class Stack {
private:
  static const int MAX_SIZE =
      100; // maximum size of Stack, immutable, memory allocated at compile time
  int top;
  char data[MAX_SIZE];

public:
  Stack() : top(-1) {} // constructor

  // check if the stack is empty
  bool isEmpty() { return top == -1; }

  // check if the stack is full
  bool isFull() { return top == MAX_SIZE - 1; }

  // push an element onto the stack
  void push(char value) {
    if (!isFull()) {
      data[++top] = value;
    } else {
      cout << "Stack Overflow" << endl;
    }
  }

  // pop an element from the stack
  char pop() {
    if (!isEmpty()) {
      return data[top--];
    } else {
      cout << "Stack Underflow" << endl;
      return '\0'; // assuming null character for simplicity
    }
  }

  // peek at the top element of the stack
  char peek() {
    if (!isEmpty()) {
      return data[top];
    } else {
      cout << "Stack is Empty" << endl;
      return '\0'; // assuming null character for simplicity
    }
  }
};

// function to get precedence of an operator
int getPrecedence(char op) {
  if (op == '+' || op == '-')
    return 1;
  else if (op == '*' || op == '/')
    return 2;
  else
    return 0; // assuming other characters have precedence 0
}