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
    Node* tail;

    public:
        List(){
            tail = head = NULL;
        }

        void push_front(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = newNode;
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
                head = tail = newNode;
                return;
            } else {
                tail->next = newNode;
                tail = newNode;
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
        void pop_back(){
            if(head == NULL){
                cout<<"Linked List is empty.\n";
                return;
            } else {
                Node* temp = head;
                while(temp->next != tail){
                    temp = temp->next;
                }
                cout<<temp->next->data<<" Removed from back."<<endl;
                temp->next = NULL;
                delete tail;
                tail = temp;
                return;
            }
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

            if(temp == tail){
                push_back(val);
                return;
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

        void reverseLinkeList(){
            Node* curr = head;
            Node* prev = NULL;
            Node* nextNode = NULL;

            tail = curr;

            while (curr != NULL){
                nextNode = curr->next;
                curr->next = prev;
                prev=curr;
                curr=nextNode;
            }
            head = prev;
        }
};

int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);    
    ll.display();
    ll.reverseLinkeList();
    ll.display();
    return 0;
}