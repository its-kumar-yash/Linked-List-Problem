/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.
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


Node* reverseKGroup(Node* head, int k){
    //base case
    if( head == NULL){
        return head;
    }

    Node* ptr = head;
    for(int i = 0; i < k; i++){
        if(ptr == NULL){
            return head;
        }
        ptr = ptr->next;
    }

    //step 1 - reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++; 
    }

    //step 2 - remaining nodes will be done by recursion

    if( head != NULL){
        head->next = reverseKGroup(next, k);
    }

    //step 3 - return prev
    return prev;
}


void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data<< " ";
        temp = temp->next;
    }
}

//[1,2,3,4,5]

int main(){
    
    Node* head = new Node(1);
    Node* n1 = new Node(2);
    Node* n2 = new Node(3);
    Node* n3 = new Node(4);
    Node* n4 = new Node(5);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Node* newHead = reverseKGroup(head, 2);

    display(newHead);
    return 0;
}