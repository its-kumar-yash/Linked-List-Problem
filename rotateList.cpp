//Given the head of a linked list, rotate the list to the right by k places.

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

// int findLength(Node* head){
//     Node* ptr = head;
//     int cnt = 0;
//     while(ptr != NULL){
//         ptr = ptr->next;
//         cnt++;
//     }

//     return cnt;
// }

Node* rotateRight(Node* head, int k) {

    //base case
    if( k <= 0 || head == NULL || head->next == NULL){
        return head;
    }

    Node* end = head;

    int length = 1;
    while(end->next != NULL){
        end = end->next;
        length++;
    }
    end->next = head;

    int rotations = k % length;

    Node* newLast = head;
    for(int i = 0; i < (length - rotations - 1); i++){
        newLast = newLast->next;
    } 

    Node* newHead = newLast->next;
    newLast->next = NULL;

    return newHead;
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

    Node* newHead = rotateRight(head, 2);

    display(newHead);
    return 0;
}