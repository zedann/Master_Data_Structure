#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
class LinkedStack{
    private:
    struct Node
    {
        int data { };
        Node*next { };
        Node(int data):data(data){ }
    };
    Node*head { };

    public:
    void push(int value)
    {
        Node*item = new Node(value);
        item->next = head;
        head = item;
    }
    int pop(){
        assert(!isEmpty());
        Node*cur = head;
        int element = head->data;
        head = head->next;
        delete cur;
        return element;
    }
    int peek(){
        assert(!isEmpty());
        int top = head->data;
        return top;
    }
    bool isEmpty(){
        return !head;
    }
};

int main()
{

}