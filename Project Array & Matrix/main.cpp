#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*next {};
    Node*prev {};
    Node(int val){
        data = val;
    }
};

class ArrayLinkedList{
    private:
        Node*head {};
        Node*tail {};
        int length = 0;
    public:
    ArrayLinkedList(int size){
        create_linkedList(size);
    }
    void print_array(){
        Node*cur = head;
        while (cur)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
    void print_array_nonzero(){
        Node*cur = head;
        while (cur)
        {
            if(cur->data)
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
    int get_value(int idx){
        Node*cur = head;
        for(int i = 0 ; i < idx ; i ++){
            cur = cur->next;
        }
        return cur->data;
    }
    void create_linkedList(int size){
        for (int i = 0; i < size; i++)
        {
            insert_end(0);
        }
    }
    void set_value(int val , int idx){
        Node*cur = head;
        for(int i = 0 ; i < idx ; i ++){
            cur = cur->next;
        }
        cur->data = val;
    }
    void insert_end(int val){
        Node*item = new Node(val);
        if(!head){
            head = tail = item;
            item->next = nullptr;
            item->prev = nullptr;
        }else {
            tail->next = item;
            tail = item;
            item->next=nullptr;
        }
        length++;
    }
};
int main(){
    ArrayLinkedList array(10);
    array.set_value(50,5);
    array.set_value(20,2);
    array.set_value(70,7);
    array.set_value(40,4);
    array.print_array();
    array.print_array_nonzero();
    cout << array.get_value(7) << "\n";
    return 0;
}