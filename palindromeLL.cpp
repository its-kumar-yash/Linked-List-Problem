//Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

//asked in - linked-in, amazon, facebook, google, apple, microsoft

#include<bits/stdc++.h>
using namespace std;

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

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool palindrome(Node* head){

    //step 1 - find the mid of the LL
    Node* mid = getMid(head);

    //step 2 - reverse the second half of the LL
    Node* secondHead = reverse(mid);
    //to re-reverse the second half
    Node* reverseHead = secondHead;
    
    //step 3 - compare the first and second half
    while(head != NULL && secondHead != NULL){
        if(head->data != secondHead->data){
            break;
        }
        head = head->next;
        secondHead = secondHead->next;
    }

    //step 4 - re - reverse the second half
    reverseHead = reverse(reverseHead);

    return head == NULL || secondHead == NULL;
}

int main(){
    
    Node* head = new Node(1);
    Node* n1 = new Node(2);
    Node* n2 = new Node(3);
    Node* n3 = new Node(3);
    Node* n4 = new Node(2);
    Node* n5 = new Node(1);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    if(palindrome(head)){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not Palindrome"<<endl;
    }
    return 0;
}