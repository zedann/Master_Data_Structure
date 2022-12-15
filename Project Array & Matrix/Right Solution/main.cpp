#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    int index;
    Node*next { };
    Node*prev { };
    Node(int data,int index):data(data),index(index){ };
};

class ArrayLinkedList{
    private:
    Node*head{ };
    Node*tail{ };
    int length = 0;
    int array_length { };
    void link(Node*first,Node*second){
        if(first)
        first->next = second;
        if(second)
        second->prev = first;
    }
    Node*embed_after(Node*node_before,int data , int index){
        Node*middle = new Node(data,index);
        ++length;
        Node*node_after = node_before->next;
        link(node_before,middle);
        if(!node_after)
        tail = middle;
        else 
        link(middle,node_after);

        return middle;
    }

    Node*get_index(int index , bool is_create_if_missing){
         Node*prev_index = head;
         while (prev_index->next && prev_index->index < index)
            prev_index = prev_index->next;
        bool found = prev_index->next && prev_index->next->index == index;
        if(found)
        return prev_index->next;
        if(!is_create_if_missing)
        return nullptr;

        return embed_after(prev_index,0,index);
    }

    public:
    ArrayLinkedList(int array_length):array_length(array_length)
    {
        //dummy node
        tail = head = new Node(0,-1);
        ++length;
    }
    void print_array(){
        Node*cur = head->next;
        for(int i = 0 ; i < array_length ; ++i){
            if(cur&&cur->index == i){
                cout << cur->data << " ";
                cur = cur->next;
            }else {
                cout << "0 ";
            }
            cout << "\n";
        }
    }
    void print_array_nonzero(){
        for(Node*cur = head->next;cur;cur=cur->next)
            cout<< cur->data << " ";
        cout << "\n";
    }
    int get_value(int index){
        Node*node = get_index(index,false);
        if(!node)
            return 0;
        return node->data;

    }
    void set_value(int data,int index){
        get_index(index,true)->data = data;
    }
    
};


int main(){
    
    

    return 0;
}