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


bool isOperator(char op){
    if(op == '+' || op == '-' || op == '*' || op == '/')
        return true;
    return false;
}
int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}
void infixToPostfix(string &infix){ //O(n)
        stack<char>operators;
        string postfix = "";
        for (int i = 0; i < infix.size(); i++)
        {
            if(!isOperator(infix[i])){
                postfix += infix[i];
            }else {
                while (!operators.empty() && precedence(operators.top()) >= precedence(infix[i])) // parallel n items
                {
                    postfix +=operators.top();
                    operators.pop();
                }
                operators.push(infix[i]); 
            }
        }
        while (!operators.empty())
        {
            postfix += operators.top();
            operators.pop();
        }
        infix = postfix;
}
bool is_digit(char c){
    int n = (c - '0');
    cout << n << "\n";
    return n >= 0 && n <= 9;
}
void infixToPostfix2(string &infix){
    stack<char>s;
    string postfix = "";
    for (int i = 0; i < infix.size(); i++)
    {
        if(is_digit(infix[i])){
            postfix+=infix[i];
        }else if (infix[i] == '('){
            s.push(infix[i]);
        }else if (infix[i] == ')'){
            while (s.top()!='(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }else {
            while (precedence(s.top()) >= precedence(infix[i]))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    infix = postfix;
    
}
int main() {
    cout << is_digit('0');
    string str= "2+3*(5+2*3)";
    infixToPostfix2(str);
    cout << str << "\n";
    
    

	return 0;
}
