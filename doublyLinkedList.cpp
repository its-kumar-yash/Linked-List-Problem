#include<bits/stdc++.h>
using namespace std;


//create a new node
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

//Insert at head
void insertAtHead(Node* &head, int data){
    //creating a new node
    Node* temp = new Node(data);

    //connections
    temp->next = head;
    head->prev = temp;
    head = temp;
}

//Insert at Position
void insertAtPosition(Node* &head, int data, int position){
    //creating a new node
    Node* temp = new Node(data);

    Node* curr = head;
    //traversing to position
    for(int i= 0; i< position - 1; i++){
        curr = curr->next;
        i++;
    }

    //connections
    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
}

//Insert at End
void insertAtEnd(Node* &head, int data){
    //creating a new node
    Node* temp = new Node(data);

    Node* curr = head;
    //traversing to end
    while(curr->next != NULL){
        curr = curr->next;
    }

    //connections
    curr->next = temp;
    temp->prev = curr;
}


//delete at head
void deleteAtHead(Node* &head){
    //dumming node of head
    Node* temp = head;
    head = head->next;
    cout<<temp->data<<endl;
    delete temp;
}

//delete at end
void deleteAtEnd(Node* &head){
    //dumming node 
    Node* prev = head;
    Node* curr = head->next;
    //traversing to end
    while(curr->next != NULL){
        prev = prev->next;
        curr = curr->next;
    }

    //connections
    prev->next = NULL;
    cout<<curr->data<<endl;
    delete curr;
}

//delete at position
void deleteAtPosition(Node* &head, int position){
    //dumming nodes
    Node* prev = head;
    Node* curr = head->next;
    //traversing to position
    for(int i = 0; i < position - 1; i++){
        prev = prev->next;
        curr = curr->next;
    }

    //connections
    prev->next = curr->next;
    curr->next->prev = prev;
    cout<<curr->data<<endl;
    delete curr;
}

//treversing doubly linked list
void display(Node* head){
    Node* temp = head;
    while( temp != NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){

    Node* head = new Node(10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtEnd(head, 40);
    insertAtPosition(head, 22, 1);
    deleteAtHead(head);
    deleteAtEnd(head);
    deleteAtPosition(head, 1);
    display(head);


    return 0;
}