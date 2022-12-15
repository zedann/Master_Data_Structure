#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
class LinkedList 
{

    struct Node
    {
        int data;
        Node*next;
    };
    Node*head { };
    Node*tail { };
    int length = 0;
    public:
    LinkedList()
    {
        head = tail = nullptr;
        length = 0;
    }
    void insert_end(int value)
    {
        Node*item = new Node;
        item->data = value;
        if(!head){
            head = tail = item;
            item->next = nullptr;
        }else {
            tail->next = item;
            tail= item;
            item->next = nullptr;
        }
        length++;
    }
    Node* get_head()
    {
        return head;
    }
    Node* get_tail()
    {
        return tail;
    }
    void delete_first()
    {
        assert(length);
        head = head->next;
        length--;
    }
    int size()
    {
        return length;
    }
    void print()
    {
        Node*cur = head;
        while (cur)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }

};

class QueueList
{
    LinkedList list;
    public :
    void enqueue(int value)
    {
        list.insert_end(value);
    }
    void dequeue()
    {
        list.delete_first();
    }
    void display()
    {
        list.print();
    }
    int get_front()
    {
        return list.get_head()->data;
    }
    int get_rear()
    {
        return list.get_tail()->data;
    }
    bool isEmpty()
    {
        return list.size() == 0;
    }
};

int main()
{
    QueueList q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
}