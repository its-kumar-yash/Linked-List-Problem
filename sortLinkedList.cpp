//Given the head of a linked list, return the list after sorting it in ascending order.

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

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge(Node* l1, Node* l2){
    Node* f = l1;
    Node* s = l2;
    Node* preHead = new Node(0);
    Node* p = preHead;

    while( f && s){
        if( f->data <= s->data){
            p->next = f;
            p = p->next;
            f = f->next; 
        }
        else{
            p->next = s;
            p = p->next;
            s = s->next;
        }
    }

    while( f ){
        p->next = f;
        p = p->next;
        f = f->next; 
    }

    while( s ){
        p->next = s;
        p = p->next;
        s = s->next;
    }

    return preHead->next; 
}

Node* sortList(Node* head){
    //base case
    if( head == NULL || head->next == NULL){
        return head;
    }

    //break ll into 2 halves, after finding mid
    Node* mid = getMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    //recursive calls to sort the both halves
    left = sortList(left);
    right = sortList(right);

    //merge both halves
    Node* ans = merge(left, right);

    return ans;
}

//5->7->1->3->6

int main(){
    
    Node* head = new Node(5);
    Node* n1 = new Node(7);
    Node* n2 = new Node(1);
    Node* n3 = new Node(3);
    Node* n4 = new Node(6);

    //connections
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Node* newHead = sortList(head);

    while(newHead){
        cout<<newHead->data<<" ";
        newHead = newHead->next;
    }


    return 0;
}