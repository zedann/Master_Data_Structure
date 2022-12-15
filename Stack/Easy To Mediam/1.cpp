#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
	int size { };
	int top { };
	int*array;
public:
	Stack(int size):top(-1),size(size){ 
        array= new int[size];//O(n) memory
    };
    ~Stack(){
        delete[] array;
    }
	void push(int item){
		if(isFull())
            cout << "OverFlow!!\n";
        else 
            array[++top] = item;
	}
    int pop(){
        if(isEmpty())
            cout << "UnderFlow!!\n";
        else 
            return array[top--]; 
    }
    int peek(){
        if(isEmpty())
            cout << "UnderFlow!!\n";
        else 
            return array[top]; 
        
    }
    //display function
    void display(){
        for (int i = top; i >= 0; i--)
            cout << array[i] << "\n";
    }
    //valid functions
    bool isFull(){
        return top == size - 1;
    }
    bool isEmpty(){
        return top == -1;
    }
};

int main() {

    Stack s(4);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();

	return 0;
}
