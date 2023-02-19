#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
struct Node {
        int data { };
        Node*left { };
        Node*right { };
        Node(int data):data(data){
        }
};

class BinaryTree
{
    private:
    Node*root { };
    void print_inorder(Node*current)
    {
        if(!current)
        return;
        print_inorder(current->left);
        cout << current->data << " ";
        print_inorder(current->right);
    }
    public:
    BinaryTree(int root_value)
    {
         root = new Node(root_value);
    }
    void print_inorder()
    {
        print_inorder(root);
        cout << "\n";
    }
    void add(vector<int>values , vector<char>direction )
    {
        assert(values.size() == direction.size());
        Node*cur = root;
        for (int i = 0; i < (int)values.size(); i++)
        {
            if(direction[i] == 'L'){
                if(!cur->left){
                cur->left = new Node(values[i]);
                }else{
                    assert(cur->left->data == values[i]);
                }
                cur = cur->left;
            }else {
                if(!cur->right){
                cur->right = new Node(values[i]);
                }else{
                    assert(cur->right->data == values[i]);
                }
                cur = cur->right;
            }
        }
    }
};
int main()
{
    BinaryTree bt(1);
    bt.add({1,2,3},{'L','L','L'});
    bt.print_inorder();
}