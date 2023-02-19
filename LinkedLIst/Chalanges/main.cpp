#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

struct Node {
	int data { };
	Node* next { };
	

	// ~Node() {
	// 	//To easily test your nodes are destructed
	// 	cout << "Destroy value: " << data << "\n";
	// }
};

class LinkedList {
private:
	Node *head { };
	Node *tail { };
	int length = 0;	// let's maintain how many nodes

public:

	void print() {
		// DON'T change head itself
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}
    
	void insert_end(int value) {
		Node* item = new Node();
        item->data = value;
		if (!head){
            item->next = nullptr;
			head = tail = item;
        }
		else{
			tail->next = item, item->next = nullptr,tail = item  ;

        }
		++length;
	}
    ///////////////////////////P 2
	void insert_front(int val){
        Node*newNode = new Node();
        newNode->data = val;
        if(!head){
            newNode->next = nullptr;
            head=tail=newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
        length++;
    }
    //////////////////O(1)//////P3
    void delete_front(){
        assert(length);
        Node*cur = head;
        head = head->next;
        delete cur;
    }
    ////////////time O(n)///////memory O(1)//////////p4
    int get_nth_back(int pos){
        if(pos==1)
        return tail->data;
        else{
            if(!length)
            cout << "Empty!!\n";
            else{
                Node*temp_head =head;
               for (int i = 0; i < length-pos; i++)
               {
                temp_head = temp_head->next;
               }
               return temp_head->data;   
            }
        }
    }
    ///////////////p5
    bool is_same(const LinkedList &l2){
        if(length != l2.length)
        return false;
        else{
            Node*temp_head2 = l2.head;
            Node*temp_head =  head;
            while (temp_head != nullptr && temp_head2 != nullptr)
            {
                if(temp_head->data != temp_head2->data){
                    return false;
                }
                temp_head2 = temp_head2->next;
                temp_head = temp_head->next;
            }
            return true;
            
        }
    }
    //reverse 
    void reverse(){
        Node*cur = head;
        Node*prev = nullptr;
        Node*next = nullptr;
        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            if(!next)
            head = cur;
        }
        
    }
    Node*get_head(){
        return head;
    }
    //////////////////////
    int get_length(){
        return length;
    }
    /////////////O(n) O(1)//////////P1
    ~LinkedList(){
        while (head!=nullptr)
        {
            Node*cur = head;
            delete head;
            cur = cur->next;
            head = cur;
        }
        
    }
};


int main() {

	LinkedList list1;
	list1.insert_end(1);
	list1.insert_end(2);
	list1.insert_end(3);
	list1.insert_end(4);
    // list1.reverse();
    list1.print();
    
	return 0;
}

