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

	BinarySearchTree(int data , BinarySearchTree*left = nullptr , BinarySearchTree*right = nullptr ) {
		this->data = data;
		this->left = left;
		this->right = right;
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
    bool search_iterative(int target)
    {
        BinarySearchTree*cur = this;
        while (cur)
        {
            if(target == cur->data)
            return true;
            if(target < data)
            cur = cur->left;
            else 
            cur = cur->right;
        }
        return false;   
    }
    bool is_bst()
    {
        
		//second solution we can put values inorder in vector if they are sorted => bst else its not;
    }
	BinarySearchTree* build_balanced_bst(vector<int>&values , int start= 0 , int end = -10)
	{
		if(end == -10)
		end = values.size() - 1;

		if(start > end)
		return nullptr;

		int mid = start + (end - start)/2;
		BinarySearchTree*left = build_balanced_bst(values,start,mid-1);
		BinarySearchTree*right = build_balanced_bst(values,mid+1,end);
		BinarySearchTree*root = new BinarySearchTree(values[mid],left,right);
		return root;
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

};

int main() {	

	cout << "bye\n";

	return 0;
}

