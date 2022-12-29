//To find the length of length of cycle present in the cycle 

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

    while(slow != NULL || fast != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
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

    cout<<"Cycle Length: "<<cycleLength(head)<<endl;

    return 0;
}