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
    public:
        Node* head;
        Node* tail;
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


        void middleOfLinkeList(){
            Node* slow = head;
            Node* fast = head;

            while (fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            cout<<"Middle of the linked list is: "<<slow->data<<endl;
        }


        bool hasCycle(){

            Node* slow = head;
            Node* fast = head;

            while (fast != NULL && fast->next == NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast)
                {
                    return true;
                }
            }
            return false;
        }

        
};

Node* merge2Lists(Node* h1, Node* h2){

    if (h1 == NULL || h2 == NULL) {
        return h1 == NULL ? h2 : h1;
    }
    

    if (h1->data <= h2->data)
    {
        h1->next = merge2Lists(h1->next, h2);
        return h1;
    } else {
        h2->next = merge2Lists(h1, h2->next);
        return h1;
    }
}

int main(){
    List ll;
    List ll2;
    ll.push_back(2);
    ll.push_back(4);
    ll.push_back(3);
    ll.display();
    ll2.push_back(5);
    ll2.push_back(6);
    ll2.push_back(4);
    
    // ll.display();
    cout<<endl;
    ll2.display();

    // cout<<ll.hasCycle();
    // cout<<merge2Lists(ll.head, ll2.head);
    return 0;
}
