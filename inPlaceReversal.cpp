//asked in google, microsoft , apple, amazon
//Iterative Solution (Two Pointer) (inplace)

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

void reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data<< " ";
        temp = temp->next;
    }
}

// 3->5->7->9

int main(){
    
    Node* head = new Node(3);
    Node* n1 = new Node(5);
    Node* n2 = new Node(7);
    Node* n3 = new Node(9);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;

    
    reverse(head);

    display(head);

    return 0;
}