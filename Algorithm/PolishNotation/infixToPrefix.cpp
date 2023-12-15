#include "myStack.cpp"
using namespace std;

// function to convert infix expression to prefix
string infixToPrefix(string infix) {
  Stack operators;
  string prefix;

  // iterate through each character in the infix expression in reverse order
  for (int i = infix.size() - 1; i >= 0; --i) {
    char c = infix[i];

    if (isalnum(c)) {
      // if the character is an operand, append it to the prefix expression
      prefix = c + prefix;
    } else if (c == ')') {
      // if the character is a closing parenthesis, push it onto the stack
      operators.push(c);
    } else if (c == '(') {
      // if the character is an opening parenthesis, pop operators from the
      // stack until a closing parenthesis is encountered
      while (!operators.isEmpty() && operators.peek() != ')') {
        prefix = operators.pop() + prefix;
      }
      operators.pop(); // pop ')'
    } else {
      // if the character is an operator, pop operators from the stack until the
      // stack is empty or an operator with lower precedence is encountered
      while (!operators.isEmpty() &&
             getPrecedence(operators.peek()) > getPrecedence(c)) {
        prefix = operators.pop() + prefix;
      }
      operators.push(c);
    }
  }

  // pop any remaining operators from the stack
  while (!operators.isEmpty()) {
    prefix = operators.pop() + prefix;
  }

  return prefix;
}

int main() {
  string infixExpression;
  cout << "enter an infix expression: ";
  getline(cin, infixExpression);

  string prefixExpression = infixToPrefix(infixExpression);
  cout << "prefix expression: " << prefixExpression << endl;
  return 0;
}