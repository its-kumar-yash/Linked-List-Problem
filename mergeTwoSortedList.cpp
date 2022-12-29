/*

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

*/

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

void insertAtEnd(Node* &head, int val){
    
    
    Node* temp = new Node(val);
    Node* prev = head;
    while(prev->next != NULL){
        prev = prev->next;
    }

    prev->next = temp;
    temp->next = NULL;
    
}

void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data<< " ";
        temp = temp->next;
    }
}

Node* merge(Node* head1, Node* head2){
    Node* first = head1;
    Node* second = head2;
    Node* preHead = new Node(0);

    
    while(first != NULL && second != NULL){
        if(first->data < second->data){
            insertAtEnd(preHead, first->data);
            first = first->next;
        }
        else{
            insertAtEnd(preHead, second->data);
            second = second->next;
        }
    }

    while(first != NULL){
        insertAtEnd(preHead, first->data);
        first = first->next;
    }

    while(second != NULL){
        insertAtEnd(preHead, second->data);
        second = second->next;
    }

    return preHead->next;
}


int main(){
    
    Node* head1 = new Node(1);
    Node* head2 = new Node(1);

    insertAtEnd(head1, 2);
    insertAtEnd(head1, 4);
    insertAtEnd(head2, 3);
    insertAtEnd(head2, 5);
    insertAtEnd(head2, 6);

    Node* head3 = merge(head1, head2);

    display(head3);
    return 0;
}