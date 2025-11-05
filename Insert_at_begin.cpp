#include <iostream> 
using namespace std; 
// Node structure 
struct Node { 
int data; 
Node* next; 
}; 
// Head pointer (start of linked list) 
Node* head = NULL; 
// a) Insert at Beginning 
void insertAtBegin(int value) { 
Node* newNode = new Node(); // create new node 
newNode->data = value;  
newNode->next = head;   
head = newNode; 
// assign data 
// link to current head 
// update head 
cout << value << " inserted at beginning.\n"; 
} 
// b) Delete from Beginning 
void deleteFromBegin() { 
if (head == NULL) { 
cout << "List is empty. Nothing to delete.\n"; 
return; 
} 
Node* temp = head; 
// store current head 
cout << "Deleted node: " << head->data << endl; 
head = head->next;  
// move head to next node 
delete temp; 
} 
// c) Display Linked List 
void displayList() { 
if (head == NULL) { 
// free memory 
cout << "List is empty.\n"; 
return; 
} 
Node* temp = head; 
cout << "Linked List elements: "; 
while (temp != NULL) { 
cout << temp->data << " -> "; 
temp = temp->next; 
} 
cout << "NULL\n"; 
} 
// d) Count number of elements 
void countNodes() { 
int count = 0; 
Node* temp = head; 
while (temp != NULL) { 
count++; 
temp = temp->next; 
} 
cout << "Total number of nodes: " << count << endl; 
} 
// ---------- Main Function ---------- 
int main() { 
int choice, value; 
while (true) { 
cout << "\n--- Singly Linked List Menu ---\n"; 
cout << "1. Insert at Beginning\n"; 
cout << "2. Delete from Beginning\n"; 
cout << "3. Display List\n"; 
cout << "4. Count Nodes\n"; 
cout << "5. Exit\n"; 
cout << "Enter your choice: "; 
cin >> choice; 
switch (choice) { 
case 1: 
cout << "Enter value to insert: "; 
cin >> value; 
insertAtBegin(value); 
break; 
case 2: 
deleteFromBegin(); 
break; 
case 3: 
displayList(); 
break; 
case 4: 
countNodes(); 
break; 
case 5: 
cout << "Exiting program.\n"; 
return 0; 
default: 
cout << "Invalid choice. Try again.\n"; 
} 
} 
}