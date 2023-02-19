#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
struct Node
    {
        int data { };
        Node*left { };
        Node*right { };
        Node(int data):data(data){
        }
};

class BinaryTree
{
    
    Node*root = new Node(1);
    Node*node2 = new Node(2);
    Node*node3 = new Node(3);
    Node*node4 = new Node(4);
    Node*node5 = new Node(5);
    Node*node6 = new Node(6);
    Node*node7 = new Node(7);
    
    public:
    BinaryTree()
    {
        root->left = node2;
        root->right = node3;
        node2->left = node4;
        node2->right = node5;
        node3->right = node6;
        node3->left = node7;
        print(root);
    }
    void print(Node*root){
        if(!root->left || !root->right )
        return;
        cout << "parent:" << root->data << "childrens" << root->left->data  << "," << root->right->data << "\n";
        print(root->left);
        print(root->right);
    }
    
    
};
int main()
{
    BinaryTree bt;
}