#include <iostream> 
#include <cstdlib> 
#include <cstring> 
using namespace std; 
struct student { 
int ID; 
char name[40]; 
float cgpa; 
}; 
void accept(student *s, int n){ 
for(int i = 0; i < n; i++){ 
cout << "\nStudent " << i + 1 << ":\nID: "; 
cin >> s[i].ID; 
cout << "Name: "; 
cin >> s[i].name; 
cout << "CGPA: "; 
cin >> s[i].cgpa; 
} 
} 
void display(student *s, int n){ 
for(int i = 0; i < n; i++) 
cout << "\nID:" << s[i].ID 
<< "\nName:" << s[i].name 
<< "\nCGPA:" << s[i].cgpa << endl; 
} 
void selectionSortByCGPA(student *s, int n) 
{ 
student temp; 
for(int i = 0; i < n - 1; i++) 
{ 
int min_idx = i; 
for(int j = i + 1; j < n; j++) 
if(s[j].cgpa < s[min_idx].cgpa) 
min_idx = j; 
temp = s[i]; 
s[i] = s[min_idx]; 
s[min_idx] = temp; 
}
cout<<"\nStudents sorted by CGPA (Low-High):\n";
} 
int main(){ 
student *s = NULL; 
int n = 0, choice; 
while(true){ 
cout << "\n---Menu---\n1.Add Students\n2.Display\n3.Selection Sort by CGPA\n4.Exit\nChoice: "; 
cin >> choice; 
switch(choice){ 
case 1:{ 
int add; 
cout << "Number of students: "; 
cin >> add; 
s = (student*)realloc(s, (n + add) * sizeof(student)); 
accept(&s[n], add); 
n += add; 
break; 
} 
case 2: 
if(n == 0) 
cout << "Database empty.\n"; 
else 
display(s, n); 
break; 
case 3: 
if(n == 0) 
cout << "Database empty.\n"; 
else 
selectionSortByCGPA(s, n); 
break; 
case 4: 
free(s); 
exit(0); 
default: 
cout << "Invalid choice.\n"; 
} 
} 
}