#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*next{};
    Node*prev{};
};
class DLL {
    private:
    Node*head {};
    Node*tail {};
    int length = 0;
    public:
    DLL(){
        head = tail = nullptr;
    }
    void insert_end(int val)
    {
        Node*item = new Node();
        item->data = val;
        if(!head){
            item->next = nullptr;
            head=tail=item;
        }else {
            tail->next=item;
            item->prev = tail;
            item->next = nullptr;
            tail=item;
        }
        length++;
    }
    void insert_first(int val){
        Node*item = new Node();
        item->data = val;
        if(!head){
            item->next = nullptr;
            head=tail=item;
        }else {
            item->next = head;
            head->prev = item;
            item->prev = nullptr;
            head = item;
        }
        length++;
    }
    void insert_sorted(int val){
        Node*item = new Node();
        item->data = val;
        if(!head){
            item->next = nullptr;
            head=tail=item;
            length++;
        }else if(val>=tail->data){
            insert_end(val);
        }
        else {
            for(Node*cur = head,*prev;cur;prev=cur,cur=cur->next){
                if(val <= cur->data)
                {
                    if(val<=head->data){
                        insert_first(val);
                        return;
                    }
                    cur->prev = item;
                    item->next = cur;
                    prev->next = item;
                    length++;
                }
            }
        }
    }
    int getLength(){
        return length;
    }
    bool empty(){
        return !tail;
    }
    void delete_first(){
        assert(length);
        head = head->next;
        head->prev = nullptr;
        --length;
    }
    void delete_end(){
        assert(length);
        tail=tail->prev;
        tail->next = nullptr;
        --length;
    }
    void delete_with_key(int val){
        assert(length);
        if(head->data == val){
            delete_first();
            return;
        }else if(val == tail->data) {
            delete_end();
            return;
        }else {
            for(Node*cur  = head,*prev; cur; prev=cur,cur=cur->next){
                if(cur->data == val){
                    prev->next = cur->next;
                    cur->next->prev = prev;
                    length--;
                    return;
                }
            }
        }
    }
    void print(){
        for (Node*cur  = head; cur; cur=cur->next)
        {
            cout << cur->data << " ";
        }
        cout << "\n";
    }
    void print_reverse(){
        for(Node*cur = tail ; cur ; cur=cur->prev)
            cout << cur->data << " ";
        cout << "\n";
    }
    //////////easy to mediam
    void delete_all_nodes_with_key(int val){
        assert(length);
        
    }
};
int main(){
    DLL dl;
    dl.insert_end(1);
    dl.insert_end(2);
    dl.insert_end(3);
    dl.insert_end(1);
    dl.insert_end(4);
    dl.insert_end(4);
    dl.insert_end(5);
    dl.insert_end(3);
    dl.insert_end(5);
    dl.insert_end(2);
    dl.insert_end(1);
    dl.delete_all_nodes_with_key(1);
    cout << "Length : " << dl.getLength() << "\n";
    dl.print();
    // dl.print_reverse();
    return 0;
}