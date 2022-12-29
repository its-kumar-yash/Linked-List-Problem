#include<bits/stdc++.h>
using namespace std;

//Node Class Definition
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//Insert At Head
void insertAtHead(Node* &head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

//Insert At Position
void insertAtPosition(Node* &head, int position, int val){
    Node* temp = new Node(val);
    Node* prev = head;
    int i = 0;
    while(i != position - 1){
        prev = prev->next;
        i++;
    }

    temp->next = prev->next;
    prev->next = temp;
}

//Insert At End
void insertAtEnd(Node* &head, int val){
    Node* temp = new Node(val);
    Node* prev = head;
    while(prev->next != NULL){
        prev = prev->next;
    }

    prev->next = temp;
    temp->next = NULL;
    
}

//Delete first node
void deleteFirstNode(Node* &head){
    Node* temp = head;
    head = head->next;
    cout<<temp->data<<endl;
    delete temp;
}

void deleteMiddleNode(Node* &head, int position){
    Node* prev = head;
    Node* curr = head->next;
    
    for(int i = 0; i < position - 1; i++){
        prev = prev->next;
        curr = curr->next;
    }

    prev->next = curr->next;
    cout<<curr->data<<endl;
    delete curr;
}


//Delete last node
void deleteLastNode(Node* &head){
    Node* prev = head;
    Node* curr = head->next;
    while(curr->next != NULL){
        prev = prev->next;
        curr = curr->next;
    }

    prev->next = NULL;
    cout<<curr->data<<endl;
    delete curr;
}



//traversal function
void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data<< " ";
        temp = temp->next;
    }
}




int main(){
    //New Node Creation
    Node* head = new Node(19);
    Node* second = new Node(12);
    Node* third = new Node(16);

    head->next = second;
    second->next = third;

    display(head);
    cout<<endl;

    insertAtHead(head, 1);
    display(head);
    cout<<endl;

    insertAtEnd(head, 3);
    display(head);
    cout<<endl;

    insertAtPosition(head,3, 20);
    display(head);
    cout<<endl;

    cout<<head->data<<endl;

    deleteFirstNode(head);
    display(head);
    cout<<endl;

    deleteLastNode(head);
    display(head);
    cout<<endl;

    deleteMiddleNode(head, 2);
    display(head);
    cout<<endl;

    return 0;
}