#include <iostream>
#include <algorithm>  // for reverse()
#include <cstring>
using namespace std;

// Node structure for singly linked list
struct Node {
    char data;
    Node* next;
};

// Stack class implemented using linked list
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        char value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    char peek() {
        if (!isEmpty())
            return top->data;
        else
            return '\0';
    }

    bool isEmpty() {
        return top == NULL;
    }
};

// Function to check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to return precedence of operator
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    Stack s;
    string prefix = "";

    // Step 1: Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Step 2: Swap '(' with ')' and vice versa
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 3: Convert reversed infix to postfix
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // If operand, add to result
        if (isalnum(ch)) {
            prefix += ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            s.push(ch);
        }
        // If ')', pop till '('
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                prefix += s.pop();
            }
            s.pop();
        }
        // If operator, handle precedence
        else if (isOperator(ch)) {
            while (!s.isEmpty() && precedence(s.peek()) > precedence(ch)) {
                prefix += s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.isEmpty()) {
        prefix += s.pop();
    }

    // Step 4: Reverse the postfix result to get prefix
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

// Main function
int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}