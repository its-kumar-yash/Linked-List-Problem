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
    if(k <= 1 || head == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while( true ){
        Node* last = prev;
        Node* newEnd = curr;
        int count = 0;    

        while(curr != NULL && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(last != NULL){
            last->next = prev;
        }
        else{
            head = prev;
        }

        newEnd->next = curr;

        if(curr == NULL){
            break;
        }

        prev = newEnd;
    }

    return head;
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