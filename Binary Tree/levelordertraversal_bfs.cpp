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
    void level_order_traversal1()
    {
        queue<BinaryTree*>nodes_queue;
        nodes_queue.push(this);
        while (!nodes_queue.empty())
        {
            BinaryTree*cur = nodes_queue.front();
            nodes_queue.pop();
            cout << cur->data << " ";
            if(cur->left)
            nodes_queue.push(cur->left);
            if(cur->right)
            nodes_queue.push(cur->right);
        }
        cout << "\n";
    }
	
	
};

int main() {
	

	return 0;
}

