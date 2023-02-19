#include <iostream>
#include <cassert>
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

    int prev(int pos)
    {
        return (pos - 1 + size )% size;
    }
    void enqueue_rear(int value)
    {
        assert(!isFull());
        array[rear] = value;
        rear = next(rear);
        added_elements++;
    }
    void enqueue_front(int value)
    {
        assert(!isFull());
        front=prev(front);
        array[front] = value;
        added_elements++;
    }
    void dequeue_front()
    {
        assert(!isEmpty());
        front = next(front);
        added_elements--;
    }
    void dequeue_rear()
    {
        assert(!isEmpty());
        rear = prev(rear);
        added_elements--;
    }
    //----------
    void display() {
		cout << "Front " << front << " - rear " << rear << "\t";
		if (isFull())
			cout << "full";
		else if (isEmpty()) {
			cout << "empty\n\n";
			return;
		}
		cout << "\n";

		for (int cur = front, step = 0; step < added_elements; ++step, cur = next(cur))
			cout << array[cur] << " ";
		cout << "\n\n";
	}
    int get_rear()
    {
        return array[rear];
    }
	int isEmpty() {
		return added_elements == 0;
	}

	bool isFull() {
		return added_elements == size;
	}
};

class Stack
{
    Queue q;
    int added_elements { };
    public:
    Stack(int size):q(size)
    {
    }
    void push(int value)
    {
        q.enqueue_rear(value);
        added_elements++;
    }
    void pop()
    {
        q.dequeue_rear();
        added_elements--;
    }
    int peek()
    {
        return q.get_rear();
    }
    bool isEmpty()
    {
        return q.isEmpty();
    }
    bool isFull()
    {
        return q.isFull();
    }
};


int main()
{
    Stack stk(3);
    stk.push(10);
    stk.push(20);
    stk.push(30);
    while (!stk.isEmpty())
    {
        cout << stk.peek() << " ";
        stk.pop();
    }
    
}