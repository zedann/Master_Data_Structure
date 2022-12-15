#include <iostream>
#include <cassert>
using namespace std;

class Deque 
{
    int size { };
    int front { };
    int rear { };
    int added_elements { };
    int *array { };
    public:
    Deque(int size):size(size)
    {
        array = new int[size];
    }
    ~Deque()
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

	int isEmpty() {
		return added_elements == 0;
	}

	bool isFull() {
		return added_elements == size;
	}
};

int main()
{
    Deque dq(6);
    dq.enqueue_front(3);
    dq.enqueue_front(2);
    dq.enqueue_rear(4);
    dq.enqueue_front(1);
    dq.display();
}