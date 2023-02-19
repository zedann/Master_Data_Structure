#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
	int size { };
	int top { };
	string*array;
public:
	Stack(int size):top(-1),size(size){ 
        array= new string[size];//O(n) memory
    };
    ~Stack(){
        delete[] array;
    }
	void push(string item){
		if(isFull())
            cout << "OverFlow!!\n";
        else 
            array[++top] = item;
	}
    string pop(){
        if(isEmpty())
            cout << "UnderFlow!!\n";
        else 
            return array[top--]; 
    }
    string peek(){
        if(isEmpty())
            cout << "UnderFlow!!\n";
        else 
            return array[top]; 
        
    }
    //display function
    void display(){
        for (int i = top; i >= 0; i--)
            cout << array[i] << "";
        cout << " ";
    }
    //valid functions
    bool isFull(){
        return top == size - 1;
    }
    bool isEmpty(){
        return top == -1;
    }
};
bool arePair(char open , char close){
    if((open == '(' && close == ')') || (open == '[' && close == ']') || (open == '[' && close == ']'))
        return true;
    return false;
}

bool areBalanced(string exp){
    stack<char>s;
    for (int i = 0; i < exp.length(); i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            s.push(exp[i]);
        }else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            if(s.empty() || !arePair(s.top(),exp[i]))
                return false;
            else 
            s.pop();
        }
    }
    return s.empty()?true:false;
}

string removeAllAdjacent(string str){
    
    
    
    
}

int main() {
    
    
    
	return 0;
}
