#include <iostream>
#include <cassert>
using namespace std;

struct Node {
	int data {};
	Node* next {};
	Node(int data) : data(data) {}
};

class LinkedList {
private:
	Node *head { };
	Node *tail { };
    int length = 0;
public:

	void print() {
		Node* temp_head = head;
		while(temp_head != nullptr) {
			cout<<temp_head->data<<" ";
			temp_head = temp_head->next;
		}
		cout<<"\n";
	}

	void insert_end(int value) {
		Node* item = new Node(value);

		if (!head)
			head = tail = item;
		else {
			tail->next = item;
			tail = item;
		}
        length++;
	}
    void delete_first_node(){
        assert(length);
        Node*cur = head->next;
        delete head;
        length--;
        head =cur;
    }
    void delete_last_node(){
        assert(length);
        Node*temp_head = head;
        Node*prev = head;
        while (temp_head->next != nullptr)
        {
            prev = temp_head;
            temp_head = temp_head->next;
        }
        tail = prev;
        tail->next = nullptr;
        length--;
        delete temp_head;
    }
    void delete_nth_node(int idx){
        if(idx < 0 || idx > length){
        cout << "Out Of Range!!\n";
        return;
        }
        Node*temp_head = head;
        Node*prev = head;
        for (int i = 0; i < idx; i++)
        {
            prev = temp_head;
            temp_head = temp_head->next;
        }
        prev->next = temp_head->next;
        length--;
        delete temp_head;
    }
};

int main() {

	LinkedList list;

	list.insert_end(6);
	list.insert_end(10);
	list.insert_end(8);
	list.insert_end(15);
    list.delete_nth_node(2);
    // list.delete_first_node();
    // list.delete_last_node();
	list.print();


	return 0;
}


