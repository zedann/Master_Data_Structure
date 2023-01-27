#include <bits/stdc++.h>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class BinaryTree {
private:
	int data { };
	BinaryTree* left { };
	BinaryTree* right { };

public:
	int height { };
	int n_nodes { };
	BinaryTree(int data) :
			data(data) {
	}

	void print_inorder() {
		if(left)
			left->print_inorder();
		cout << data << " ";
		if(right)
			right->print_inorder();
	}
	
	void add(vector<int> values, vector<char> direction) {
		assert(values.size() == direction.size());
		BinaryTree* current = this;
		// iterate on the path, create all necessary nodes
		for (int i = 0; i < (int) values.size(); ++i) {
			if (direction[i] == 'L') {
				if (!current->left)
					current->left = new BinaryTree(values[i]);
				else
					assert(current->left->data == values[i]);
				current = current->left;
			} else {
				if (!current->right)
					current->right = new BinaryTree(values[i]);
				else
					assert(current->right->data == values[i]);
				current = current->right;
				
			}
		}
	}
	int tree_max()
	{
		int res = data;
		if(left)
			res = max(res , left->tree_max());
		if(right)
			res = max(res , right->tree_max());
		return res;
	}
	int tree_height()
	{
		int res = 0;
		if(left)
		res = 1 + left->tree_height();
		if(right)
		res = max(res , 1+right->tree_height());
		return res;
	}
	int total_nodes()
	{
		int res = 1;
		if(left){
			res += left->total_nodes();
		}
		if(right){
			res += right->total_nodes();
		}
		return res;
	}
	int leaf_nodes()
	{
		int res = !left && !right;
        if(left)
            res+= left->leaf_nodes();
        if(right)
            res+= right->leaf_nodes();
        return res;
		
		
	}
    bool is_exist(int value)
    {
        bool res = value == data;
        if(!res && left)
            res = left->is_exist(value);
        if(!res && right)
            res = right->is_exist(value);
        return res;
    }
    bool is_perfect_formula()
    {
        int h = this->tree_height();
        int n = this->total_nodes();
        return pow(2,h+1) - 1 == n;
    }
};

int main() {
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

	cout << tree.leaf_nodes() << "\n";
	tree.print_inorder();
	// 7 4 8 2 5 9 1 3 10 6

	return 0;
}

