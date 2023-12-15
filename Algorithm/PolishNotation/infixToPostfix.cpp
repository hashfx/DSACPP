#include "myStack.cpp"
using namespace std;

// function to convert infix expression to postfix
string infixToPostfix(string infix) {
  Stack operators;
  string postfix;

  // iterate through each character in the infix expression
  for (char &c : infix) {
    if (isalnum(c)) {
      // if the character is an operand, append it to the postfix expression
      postfix += c;
    } else if (c == '(') {
      // if the character is an opening parenthesis, push it onto the stack
      operators.push(c);
    } else if (c == ')') {
      // if the character is a closing parenthesis, pop operators from the stack
      // until an opening parenthesis is encountered
      while (!operators.isEmpty() && operators.peek() != '(') {
        postfix += operators.pop();
      }
      operators.pop(); // pop '('
    } else {
      // if the character is an operator, pop operators from the stack until the
      // stack is empty or an operator with lower precedence is encountered
      while (!operators.isEmpty() &&
             getPrecedence(operators.peek()) >= getPrecedence(c)) {
        postfix += operators.pop();
      }
      operators.push(c);
    }
  }

  // pop any remaining operators from the stack
  while (!operators.isEmpty()) {
    postfix += operators.pop();
  }

  return postfix;
}

int main() {
  string infixExpression;
  cout << "enter an infix expression: ";
  getline(cin, infixExpression);

  // convert infix to postfix
  string postfixExpression = infixToPostfix(infixExpression);
  cout << "postfix expression: " << postfixExpression << endl;
  return 0;
}