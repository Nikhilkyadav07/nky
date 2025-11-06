#include <iostream> 
#include <string> 
using namespace std;
//Node structure for singly linked list 
struct Node
{
char data; 
Node* next;
};
class Stack
{
private:
Node* top; // pointer to top of stack
public:
Stack()
{
top = NULL;
}
// Push an element onto the stack 
void push(char value)
{
Node* newNode = new Node(); 
newNode->data = value; 
newNode->next = top;
top = newNode;
}
// Pop element from stack 
void pop()
{
if (isEmpty())
{
cout << "Stack Underflow\n"; 
return;
}
Node* temp = top; 
top = top->next; 
delete temp;
}
// Return top element 
char peek()
{
if (!isEmpty()) 
return top->data;
else
return '\0';
}// Check if stack is empty 
bool isEmpty()
{
return top == NULL;
}
};
// Function to define precedence of operators 
int precedence(char op)
{
if (op == '^') 
return 3;
else if (op == '*' || op == '/') 
return 2;
else if (op == '+' || op == '-') 
return 1;
else
return 0;
}
// Function to check if character is operator 
bool isOperator(char c)
{
return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
// Function to convert infix to postfix 
string infixToPostfix(string infix)
{
Stack s;
string postfix = "";
for (int i = 0; i < infix.length(); i++)
{
char c = infix[i];
// If operand, add to postfix 
if (isalnum(c))
{
postfix += c;
}
// If '(', push to stack 
else if (c == '('){
s.push(c);
}
// If ')', pop until '('
else if (c == ')')
{
while (!s.isEmpty() && s.peek() != '(') { 
postfix += s.peek();
s.pop();
}
s.pop(); // remove '('
}
// If operator
else if (isOperator(c))
{
while (!s.isEmpty() && precedence(c) <= precedence(s.peek()))
{
postfix += s.peek(); 
s.pop();
}
s.push(c);
}
}
// Pop remaining operators 
while (!s.isEmpty())
{
postfix += s.peek(); 
s.pop();
}
return postfix;
}
// Main function 
int main()
{
string infix;
cout << "Enter infix expression: "; 
cin >> infix;
string postfix = infixToPostfix(infix);
cout << "Postfix expression: " << postfix << endl;
return 0;
}