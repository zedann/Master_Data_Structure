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
        ArrayLinkedList*next;
    ArrayLinkedList(int size){
        create_linkedList(size);
    }
    Node*get_head(){
        return head;
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
    void add(ArrayLinkedList array2){
        for(Node*cur1 = head,*cur2=array2.head;cur1;cur1=cur1->next,cur2=cur2->next){
            cur1->data += cur2->data;
        }
    }
};

class SparseMatrix{
    ArrayLinkedList*head {};
    ArrayLinkedList*tail {};
    int length = 0;
    public:
    SparseMatrix(int rows,int cols){
        create_mat(rows,cols);
    }
    void create_mat(int rows,int cols){
        for (int i = 0; i < rows; i++)
        {
            addRow(cols);
        }
    }
    void addRow(int cols){
        ArrayLinkedList*row = new ArrayLinkedList(cols);
        if(!head){
            head = tail = row;
            row->next = nullptr;
        }else {
            tail->next = row;
            tail = row;
            row->next =nullptr;
        }
    }
    

};
int main(){
    ArrayLinkedList array(10);
    array.set_value(50,5);
    array.set_value(20,2);
    array.set_value(70,7);
    array.set_value(40,4);

    ///////////////////////////
    ArrayLinkedList array2(10);
    array2.set_value(1,4);
    array2.set_value(3,7);
    array2.set_value(4,6);
    array.add(array2);
    ////////////////////////////

    // array.print_array();
    // array.print_array_nonzero();
    // cout << array.get_value(7) << "\n";
    /////////////2D ARRAY/////////////
    SparseMatrix mat(10,10);
    

    return 0;
}