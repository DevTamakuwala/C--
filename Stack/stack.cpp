#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;


class Stack{
    private:
    int* stack;
    int top;
    int capacity;

    public:
        Stack(int length){
            capacity = length;
            stack = new int[length];
            top = -1;
        }
        void push(int val){
            if (isFull())
            {
                cout<<"Stack overflow"<<endl;
            } else{
                stack[++top] = val;
                cout<<val<<" pushed into the stack"<<endl;
            }
            
        }
        
        void pop(){
            if(top < 0){
                cout<<"Stack underflow";
            }else {
                cout<<stack[top--]<<" popped"<<endl;
            }
        }

        int peek(){
            if (top < 0)
            {
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            else{
                return stack[top];
            }
        }

        bool isEmpty(){
            return top == -1;
        }

        bool isFull(){
            return top >= capacity - 1;
        }

        void display(){
            if(top < 0){
                cout<<"Stack is empty";
            } else{
                for (int i = top; i >=0; i--)
                {
                    cout<<stack[i]<<" ";
                }
                cout<<endl;
            }            
        }
};


int main(){

    Stack s(4);

    s.push(10);
    s.push(20);
    cout<<"Stack full: "<<s.isFull()<<endl;
    s.push(30);
    s.push(40);
    cout<<"Stack full: "<<s.isFull()<<endl;
    s.push(50);
    s.push(60);
    s.display();
    cout<<endl;
    s.pop();
    s.display();
    cout<<endl;
    while (!s.isEmpty())
    {
        cout<<s.peek()<<" ";
        s.pop();
    }
    cout<<s.peek();
    cout<<endl;
    

    return 0;
}