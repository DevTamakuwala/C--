#include <iostream>
#include <conio.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;

    public:
        List(){
            head = NULL;
        }

        void push_front(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head  = newNode;
                return;
            } else {
                newNode->next = head;
                head = newNode;
                return;
            }
        }
        void push_back(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head =  newNode;
                return;
            } else {
                Node* tail = head;
                while (tail->next != nullptr)
                {
                    tail = tail->next;
                }
                tail->next = newNode;
                return;
            }
        }
        void pop_front(){
            if(head == NULL){
                cout<<"Linked List is empty.";
                return;
            } else {
                Node* temp = head;
                head = temp -> next;
                cout<<temp->data<<" Removed from front."<<endl;
                delete temp;
                return;
            }
        }
        void pop_back() {
            if (!head) {
                cout << "List is empty.\n";
                return;
            }

            // Only one node
            if (!head->next) {
                delete head;
                head = nullptr;
                return;
            }

            // More than one node
            Node* temp = head;
            while (temp->next->next)
                temp = temp->next;

            cout<<temp->next->data<<" Deleted"<<endl;
            delete temp->next;
            temp->next = nullptr;
        }

        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }

        void insert(int val, int index){
            if(index < 0){
                cout<<"Invalid position.\n";
                return;
            }
            if(index == 0){
                push_front(val);
                return;
            }

            Node* temp = head;
            for (int i = 0; i < index-1; i++)
            {
                if (temp->next == NULL)
                {
                    cout<<"Position index out of bound.\n";
                    return;
                }
                
                temp = temp->next;
            }

            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            
        }

        void search(int val){
            if(head == NULL){
                cout<<"Linked list is empty.";
                return;
            }

            Node* temp = head;
            int index = 0;

            while (temp != NULL)
            {
                if(temp->data == val){
                    index++;
                    cout<<val<<" Found on "<<index<<" position.\n";
                    return;
                }
                temp = temp->next;
                index++;
            }
            cout<<val<<" Not found in the list.\n";
        }
};

int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);    
    ll.display();
    ll.pop_front();
    ll.pop_front();
    ll.pop_front();
    ll.display();
    ll.pop_back();
    ll.display();
    ll.insert(4, 3);
    ll.insert(0, 0);
    ll.insert(5, 5);
    ll.display();
    ll.search(5);
    ll.search(10);
    return 0;
}