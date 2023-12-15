#include "myStack.cpp"
using namespace std;

// function to convert postfix expression to prefix
string postfixToPrefix(string postfix) {
  Stack operators;
  string prefix;

  // iterate through each character in the postfix expression
  for (char &c : postfix) {
    if (isalnum(c)) {
      // if the character is an operand, push it onto the stack
      operators.push(c);
    } else {
      // if the character is an operator, pop two operands from the stack,
      // concatenate them with the operator, and push the result back onto the
      // stack
      string operand1 = string(1, operators.pop());
      string operand2 = string(1, operators.pop());
      operators.push(c + operand2 + operand1);
    }
  }

  // the final result is the content of the stack
  return operators.pop();
}

int main() {
  string infixExpression;
  cout << "enter an infix expression: ";
  getline(cin, infixExpression);

  string postfixToPrefixExpression = postfixToPrefix(postfixExpression);
  cout << "postfix to prefix expression: " << postfixToPrefixExpression << endl;
  return 0;
}