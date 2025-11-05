#include <iostream> 
#include <cstdlib> 
#include <cstring>
#include <algorithm>
using namespace std; 
struct student { 
int ID; 
char name[40]; 
float cgpa; 
}; 
void accept(student *s, int n) { 
for (int i = 0; i < n; i++) { 
cout << "\nEnter details for student " << i + 1 << ":\n"; 
cout << "Enter ID: "; 
cin >> s[i].ID; 
cout << "Enter Name: "; 
cin >> s[i].name; 
cout << "Enter CGPA: "; 
cin >> s[i].cgpa; 
} 
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
int binarySearch(student *s, int n, int key) { 
int low = 0, high = n-1; 
while (low <= high) { 
int mid = (low + high)/2; 
if (s[mid].ID == key) return mid; 
else if (key < s[mid].ID) high = mid-1; 
else low = mid+1; 
} 
return -1; 
} 
int main() { 
student *s = NULL; 
int n = 0, choice, key; 
while (true) { 
cout << "\n--- Student Database Menu ---\n"; 
cout << "1. Add Students\n"; 
cout << "2. Display Students\n"; 
cout << "3. Linear Search by ID\n"; 
cout << "4. Binary Search by ID\n"; 
cout << "5. Exit\n"; 
cout << "Enter your choice: "; 
cin >> choice; 
switch(choice) { 
case 1: { 
int add; 
cout << "Enter number of students to add: "; 
cin >> add; 
s = (student *)realloc(s, (n+add)*sizeof(student)); 
accept(&s[n], add); 
n += add; 
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
if(n==0) { cout << "Database empty!\n"; break; } 
sort(s,s+n, [](student a, student b){return a.ID < b.ID;});
cout << "Enter ID to search (Binary): "; 
cin >> key; 
{ 
int loc = binarySearch(s,n,key); 
if(loc!=-1) 
cout << "ID found: " << s[loc].name << ", CGPA: " << s[loc].cgpa << endl; 
else 
cout << "ID not found.\n"; 
} 
break; 
case 5: 
free(s); 
exit(0); 
default: 
cout << "Invalid choice! Try again.\n"; 
} 
} 
} 