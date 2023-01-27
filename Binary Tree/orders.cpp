#include <iostream>
#include <cassert>
using namespace std;

struct Node {
	char data { };
	Node* left { };
	Node* right { };
	Node(char data) :
			data(data) {
	}
};

void print_postorder(Node* current) {
	if(!current)
		return;
	print_postorder(current->left);//left subtree => 23+ 
	print_postorder(current->right);//right subtree 4
	cout << current->data << " ";//operator *
	// 23+ 4 *
}
void print_inOrder(Node*cur)
{
	if(!cur)
	return;
    print_inOrder(cur->left);
    cout << cur->data;
    print_inOrder(cur->right);

	// 2 + 3 * 4
}


int main() {
	// (2+3) * 4 tree
	// Build plus subtree
	Node* plus = new Node('+');
	Node* node2 = new Node('2');
	Node* node3 = new Node('3');
	plus->left = node2;
	plus->right = node3;

	// Build/connect root to + *
	Node* multiply = new Node('*');
	Node* node4 = new Node('4');
	multiply->left = plus;
	multiply->right = node4;

	print_inOrder(multiply);

	return 0;
}

