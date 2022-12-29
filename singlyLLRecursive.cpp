#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* insertAtFront(Node* &head, int val){
    Node* newNode = new Node(val);

    newNode->next = head;
    head = newNode;

    return head;
}

Node* insertAtRear(Node* &head, int val){

    //Base Case
    if(head->next == NULL){
        Node* newNode = new Node(val);
        head->next = newNode;
        return head;
    }

    //Recursive call
    head->next = insertAtRear(head->next, val);

    return head;
}

Node* insertAtPosition(Node* &head, int val, int pos){
    
    if(head == NULL){
        return NULL; // if list is empty
    }

    //Base Case
    if( pos == 1){
        //craeting new node
        Node* temp = new Node(val);

        //connections
        temp->next = head->next;
        head->next = temp;

        return head;
    }

    //Recursive call
    head->next = insertAtPosition(head->next, val, pos - 1);

    return head;
}


void display(Node* head){

    if(head == NULL){
        return; // if list is empty
    }

    cout<< head->data << " ";
    display(head->next);
}

int main(){
    //Creating LL 
    Node* head = new Node(10);
    Node* second = new Node(15);
    Node* third = new Node(34);

    //Connecting
    head->next = second;
    second->next = third;
    
    display(head);
    insertAtFront(head, 20);
    cout<<endl;
    display(head);
    insertAtRear(head, 50);
    cout<<endl;
    display(head);
    insertAtPosition(head, 7, 3);
    cout<<endl;
    display(head);

    return 0;
}