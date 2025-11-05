#include <iostream> 
using namespace std; 
// Node structure 
struct Node { 
int data; 
Node* next; 
}; 
// Head pointer (start of linked list) 
Node* head = NULL; 
// a) Insert at Last 
void insertAtLast(int value) { 
Node* newNode = new Node(); 
newNode->data = value; 
newNode->next = NULL; 
if (head == NULL) { 
head = newNode; // first node 
} else { 
Node* temp = head; 
while (temp->next != NULL) { 
temp = temp->next; // move to last node 
} 
temp->next = newNode; // link new node at the end 
} 
cout << value << " inserted at last.\n"; 
} 
// b) Delete from Last 
void deleteFromLast() { 
if (head == NULL) { 
cout << "List is empty. Nothing to delete.\n"; 
return; 
} 
if (head->next == NULL) { // only one node 
cout << "Deleted node: " << head->data << endl; 
delete head; 
head = NULL; 
return; 
} 
Node* temp = head; 
Node* prev = NULL; 
while (temp->next != NULL) { 
prev = temp; 
temp = temp->next; 
} 
cout << "Deleted node: " << temp->data << endl; 
delete temp; 
prev->next = NULL; 
} 
// c) Display Linked List 
void displayList() { 
if (head == NULL) { 
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
// d) Search Element in Linked List 
void searchElement(int value) { 
if (head == NULL) { 
cout << "List is empty.\n"; 
return; 
} 
Node* temp = head; 
int position = 1; 
while (temp != NULL) { 
if (temp->data == value) { 
cout << value << " found at position " << position << ".\n"; 
return; 
} 
temp = temp->next; 
position++; 
} 
cout << value << " not found in the list.\n"; 
} 
// ---------- Main Function ---------- 
int main() { 
int choice, value; 
while (true) { 
cout << "\n--- Singly Linked List Menu ---\n"; 
cout << "1. Insert at Last\n"; 
cout << "2. Delete from Last\n"; 
cout << "3. Display List\n"; 
cout << "4. Search Element\n"; 
cout << "5. Exit\n"; 
cout << "Enter your choice: "; 
cin >> choice; 
switch (choice) { 
case 1: 
cout << "Enter value to insert: "; 
cin >> value; 
insertAtLast(value); 
break; 
case 2: 
deleteFromLast(); 
break; 
case 3: 
displayList(); 
break; 
case 4: 
cout << "Enter value to search: "; 
cin >> value; 
searchElement(value); 
break; 
case 5: 
cout << "Exiting program.\n"; 
return 0; 
default: 
cout << "Invalid choice. Try again.\n"; 
} 
} 
} 
