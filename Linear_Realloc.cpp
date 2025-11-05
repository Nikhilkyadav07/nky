#include <iostream> 
#include <cstdlib> 
#include <cstring> 
using namespace std; 
struct student { 
int ID; 
char name[40]; 
float cgpa; 
}; 
void accept(student *s) { 
cout << "Enter ID: "; 
cin >> s->ID; 
cout << "Enter Name: "; 
cin >> s->name; 
cout << "Enter CGPA: "; 
cin >> s->cgpa; 
} 
void display(student *s, int n) { 
cout << "\n--- Student Database ---\n"; 
for (int i = 0; i < n; i++) { 
cout << "\nID: " << s[i].ID; 
cout << "\nName: " << s[i].name; 
cout << "\nCGPA: " << s[i].cgpa << endl; 
} 
} 
int linearSearch(student *s, int n, int key) { 
for (int i = 0; i < n; i++) { 
if (s[i].ID == key) 
return i; 
} 
return -1; 
} 
int main() { 
student *s = NULL; 
int n = 0, choice, key; 
while (true) { 
cout << "\n--- Student Database Menu ---\n"; 
cout << "1. Add Student\n"; 
cout << "2. Display Students\n"; 
cout << "3. Linear Search by ID\n"; 
cout << "4. Exit\n"; 
cout << "Enter your choice: "; 
cin >> choice; 
switch(choice) { 
case 1: { 
s = (student *)realloc(s,(n+1)*sizeof(student)); 
accept(&s[n]); 
n++; 
break;
} 
case 2: 
if(n==0) cout << "No students in database.\n"; 
else display(s,n); 
break; 
case 3: 
if(n==0) { cout << "Database empty!\n"; break; } 
cout << "Enter ID to search (Linear): "; 
cin >> key; 
{ 
int loc = linearSearch(s,n,key); 
if(loc!=-1) 
cout << "ID found: " << s[loc].name << ", CGPA: " << s[loc].cgpa << endl; 
else 
cout << "ID not found.\n"; 
} 
break; 
case 4: 
free(s); 
exit(0); 
default: 
cout << "Invalid choice! Try again.\n"; 
} 
} 
}