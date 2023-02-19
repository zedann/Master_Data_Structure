#include <iostream>
#include <cassert>
using namespace std;
struct Node
{
    int data;
    Node*next;
};
class LinkedList{
    Node*head;
    Node*tail;
    int length = 0;
    public:
    LinkedList(){
        head = tail = nullptr;
    }
    void insert_end(int val){
        Node*newNode = new Node();
        newNode->data = val;
        if(head == nullptr)
        {
            newNode->next = nullptr;
            head = tail =newNode;
        }else {
            newNode->next = nullptr;
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    int getLength(){
        return length;
    }
    void print(){
        Node*temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
    //1
    void delete_node_with_key(int val){
        assert(length);
        Node*temp = head;
        Node*prev = head;
        if(head->data == val){
            head = head->next;
            delete temp;
            length--;
            return;
        }
        while (temp){
            if(temp->data == val){
                prev->next = temp->next;
                delete temp;
                length--;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

    }   
    //2
    void swap_pairs(){
        Node*temp = head;
        while (temp)
        {   
            if(temp->next){
                swap(temp->data,temp->next->data);
                temp = temp->next;
            }
                temp = temp->next;
        }
        
    }
    //3
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
            if(!cur){
                head = prev;
            }
        }
        
    }
    //4
    void delete_even_pos(){
        assert(length);
        
    }
    //5
    void insert_sorted(int val){
        
    }

};

int main() {
    LinkedList l;
    l.insert_end(1);
    l.insert_end(2);
    l.insert_end(3);
    l.insert_end(4);
    l.insert_end(5);
    l.insert_end(6);
    l.insert_end(7);
    // l.delete_node_with_key(1);
    // l.swap_pairs();
    // // l.reverse();
    // l.delete_even_pos();
    cout<<"Length "<<l.getLength()<<"\n";
    l.reverse();
    l.print();
	


	return 0;
}


