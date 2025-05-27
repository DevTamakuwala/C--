#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;


class Stack{
    vector<int> stack;

    public:
        void push(int val){
            stack.push_back(val);
        }
        
        void pop(){
            stack.pop_back();
        }

        int top(){
            return stack[stack.size() - 1];
        }

        bool isEmpty(){
            return stack.size() == 0;
        }

        void display(){
            for (int i = 0; i < stack.size(); i++)
            {
                cout<<stack[i]<<" ";
            }
            
        }
};


int main(){

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();
    cout<<endl;
    s.pop();
    s.display();
    cout<<endl;
    while (!s.isEmpty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    

    return 0;
}