// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.


//asked in - google , facebook 

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

Node* reorderList(Node* head){
    //step 1 - find the middle node
    Node* mid = getMid(head);

    //step 2 - reverse the second half
    Node* secondHead = reverse(mid);
    Node* firstHead = head;

    //step 3 - rearrange 
    Node* temp = NULL; //to store the next pointer
    while(firstHead != NULL && secondHead != NULL){
        temp = firstHead->next;
        firstHead->next = secondHead;
        firstHead = temp;

        temp = secondHead->next;
        secondHead->next = firstHead;
        secondHead = temp; 
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

    Node* newHead = reorderList(head);

    display(newHead);
    return 0;
}