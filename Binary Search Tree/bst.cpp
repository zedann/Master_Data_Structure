#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

class BinarySearchTree {
private:
	int data { };
	BinarySearchTree* left { };
	BinarySearchTree* right { };

public:

	BinarySearchTree(int data) :
			data(data) {
	}

	void print_inorder() {
		if(left)
		left->print_inorder();
		cout << data << " ";
		if(right)
		right->print_inorder();
	}
	bool search(int target) {	
		if(target == data)
			return true;
		if(target < data)
			return left && left->search(target);
		if(target > data)
			return right && right->search(target);
	}
	void insert(int target)
	{
		BinarySearchTree* cur = new BinarySearchTree(target);
		if(target < data){
			if(!left)
				left = cur;
			else 
				left->insert(target);
		}else if(target > data){
			if(!right)
				right = cur;
			else 
				right->insert(target);
		}
	}
    int min_value()
    {
        BinarySearchTree*cur = this;
        while (cur && cur->left)
        {
            cur = cur->left;
        }
        return cur->data; //O(h)   
    }

};

int main() {	

	cout << "bye\n";

	return 0;
}

