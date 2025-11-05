#include<iostream>
#define size 10
using namespace std;
#include<stdlib.h>
class CQ
{
private : 
	int data[30];
	int front = -1;
	int rear = -1;
	
public : 
	bool isEmpty()
	{
	if(front == -1)
		{
		return true;
		}
	else
		{
		return false;
		}
	}
	
	bool isFull()
	{
	if(front == (rear + 1)%size)
		{
		return true;
		}
	else
		{
		return false;
		}
	}
	
	void enqueue(int x)
	{
	if(isFull())
		{
		cout<<"Queue is Overflow";
		return ;
		}
	if(isEmpty())
		{
		front = rear = 0;
		data[rear]=x;
		}
	else
		{
		rear = (rear + 1)%size;
		data[rear]=x;
		}
	}
	
	int dequeue()
	{
	if(isEmpty())
		{
		cout<<"Queue is empty ,we cannot delete any element";
		return 0;
		}
	if(rear == front)
		{
		int x = data[front];
		rear = front = -1;
		return x;
		}
	else
		{
		int x = data[front];
		front = (front + 1)%size;
		return x;
		}
	
	}
	
	void display()
	{
	for(int i = front;i<=rear;i++)
		{
		cout<<data[i]<<"--->";
		}
	}
};

int main()
{
CQ q;
int ch;
int x;


while(true)
	{
	cout<<"\n--------Circular Queue Operation--------";
	cout<<"\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit";
	cout<<"\nEnter a choice : ";
	cin>>ch;
	switch(ch)
		{
		case 1:
			cout<<"\nEnter an Element to Insert : ";
			cin>>x;
			q.enqueue(x);
			break;
			
		case 2:
			x = q.dequeue();
			cout<<"\nElement Deleted "<<x;
			break;
			
		case 3:
			q.display();
			break;
			
		case 4:
        cout<<"\nExiting program.\n";
			exit(0);
			
		}
	}
}