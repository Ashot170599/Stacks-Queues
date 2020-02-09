#include <iostream>
using namespace std;
class Stack{
private:
int st[100];
int size;
int top;

public:
	Stack()
	{
		size=0;
		top=-1;
	}
	void push(int a)
	{
		if(size==100) 
		{
			cout<<"overflow\n";
			return;
		}
		st[++top]=a;
		size++;
	}
	bool isEmpty()
	{
		return size==0;
	}
	int pop()
	{
		if(size==0)
		{
			cout<<"underflow\n";
			return -1;
		}
		size--;
		return st[top--];
	}
	friend void Swap(Stack &s1,Stack &s2)
	{
		Stack s3;
		while(!s1.isEmpty())
		{
			s3.push(s1.pop());
		}
		while(!s2.isEmpty())
		{
			s1.push(s2.pop());
		}
		while(!s3.isEmpty())
		{
		s2.push(s3.pop());
	    }
	}
};

int main(){
Stack s1;
for(int i=0;i<5;i++)
s1.push(i);

Stack s2;
for(int i=10;i<15;i++)
s2.push(i);

Swap(s1,s2);

while(!s1.isEmpty())
{
	cout<<s1.pop()<<" ";
}
cout<<endl;

while(!s2.isEmpty())
{
	cout<<s2.pop()<<" ";
}
return 0;
}
