#include "myStack.cpp"
using namespace std;

// function to convert prefix expression to postfix
string prefixToPostfix(string prefix) {
  Stack operators;
  string postfix;

  // iterate through each character in the prefix expression in reverse order
  for (int i = prefix.size() - 1; i >= 0; --i) {
    char c = prefix[i];

    if (isalnum(c)) {
      // if the character is an operand, push it onto the stack
      operators.push(c);
    } else {
      // if the character is an operator, pop two operands from the stack,
      // concatenate them with the operator, and push the result back onto the
      // stack
      string operand1 = string(1, operators.pop());
      string operand2 = string(1, operators.pop());
      operators.push(operand1 + operand2 + c);
    }
  }

  // the final result is the content of the stack
  return operators.pop();
}

int main() {
  string prefixExpression;
  cout << "enter a prefix expression: ";
  getline(cin, prefixExpression);

  string prefixToPostfixExpression = prefixToPostfix(prefixExpression);
  cout << "prefix to postfix expression: " << prefixToPostfixExpression << endl;
  return 0;
}