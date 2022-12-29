//Given head of a LL, return the node where the cycle begins.

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

int cycleLength(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            int cnt = 0;
            do{
                slow = slow->next;
                cnt++;
            }while(slow != fast);

            return cnt;
        }
    }

    return 0;
}

Node* cycleStart(Node* head){
    int len = cycleLength(head);

    if( len == 0){
        return NULL;
    }


    Node* first = head;
    Node* second = head;

    for(int i = 0; i < len; i++){
        second = second->next;
    }

    while(first != second){
        first = first->next;
        second = second->next;
    }

    
    return first;
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

    Node* start = cycleStart(head);

    cout<<start->data<<endl;
    return 0;
}