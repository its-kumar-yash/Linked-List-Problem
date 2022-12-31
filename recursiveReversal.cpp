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

//Recursive Approach 1
void reverse1(Node* &head, Node* curr, Node* prev){
    //base case
    if(curr == NULL){
        head = prev;
        return;
    }

    //next pointer 
    Node* next = curr->next;
    //recursice call to reverse the remaining list
    reverse1(head, next, curr);
    //reversing the connnection of curr node
    curr->next = prev;
}

//Recursive Approach 2
Node* reverse2(Node* head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    //head of remaining node of list
    Node* newHead = reverse2(head->next);

    //reversing the connnection of head node
    head->next->next = head;
    head->next = NULL;

    return newHead;
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


    //Approach 1
    Node* prev = NULL;
    Node* curr = head;
    //reverse1(head, curr, prev);

    display(head);

    cout<<endl;

    //Approach 2

    Node* newHead = reverse2(head);

    display(newHead);

    return 0;
}