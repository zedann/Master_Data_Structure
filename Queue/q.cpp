#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;

class Queue 
{
	int size { };
	int front { };
	int rear { };
	int added_elements { };
	int *array { };

	public:
	Queue(int size):size(size)
	{
		array = new int[size];
	}
	~Queue()
	{
		delete [] array;
	}

	int next(int pos)
	{
		return (pos + 1)%size;
	}
	void enqueue(int value)
	{
		assert(!isFull());
		array[rear] = value;
		rear = next(rear);
		added_elements++;
	}
	int dequeue(){
		assert(!isEmpty());
		int value = array[front];
		front=next(front);
		--added_elements;
		return value;
	}
	void display(){
		cout << "Front "<<front << " - Rear " << rear << "\t";
		if(isFull())
		cout << "full";
		else if(isEmpty()){
			cout << "empty\n\n";
			return;
		}
		cout << "\n";
		for(int cur = front,step = 0; step < added_elements;step++,cur=next(cur))
			cout << array[cur] << " ";
		cout << "\n";
		
	}
	bool isEmpty()
	{
		return added_elements == 0;
	}
	bool isFull()
	{
		return added_elements == size;
	}

};

int main() {
     
	Queue q(6);
	q.display();
	for (int i = 1; i <= 6; i++)
	{
		q.enqueue(i);
		q.display();
	}
	q.dequeue();
	q.display();
	
    

	return 0;
}
