/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
*/

#include<bits/stdc++.h>
using namespace std;

// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 3 

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

bool checkCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL || slow != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }

    return false;
}


int main(){

    //nodes
    Node* head = new Node(1);
    Node* n1 = new Node(2);
    Node* n2 = new Node(3);
    Node* n3 = new Node(4);
    Node* n4 = new Node(5);
    Node* n5 = new Node(6);
    Node* n6 = new Node(7);

    //connections
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n2;

    if(checkCycle(head)){
        cout<<"Cycle detected"<<endl;
    }
    else{
        cout<<"Cycle Not detected"<<endl;
    }
    return 0;
}