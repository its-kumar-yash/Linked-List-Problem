/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
For more clarity have a look at the printList() function in the driver code.
*/


//24*7 Innovation Labs, Amazon, Drishti-Soft, Flipkart, Goldman Sachs, Microsoft, Paytm, Payu, Qualcomm, Snapdeal, Visa


#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* merge(Node* left, Node* right){
    Node* f = left;
    Node* s = right;
    Node* preHead = new Node(0);
    Node* p = preHead;
    
    
    while(s != NULL && f != NULL){
        if(f->data < s->data){
            p->bottom = f;
            p = p->bottom;
            f = f->bottom;
        }
        else{
            p->bottom = s;
            p = p->bottom;
            s = s->bottom;
        }
    }
    
    while(f != NULL){
        p->bottom = f;
        p = p->bottom;
        f = f->bottom;
    }
    while(s != NULL){
        p->bottom = s;
        p = p->bottom;
        s = s->bottom;
    }
    
    return preHead->bottom;
}

Node *flatten(Node *root)
{
    //base case
   if(root == NULL){
       return root;
   }
   
   
   Node* down = root;
   Node* right = root->next;
   down->next = NULL;
   
   right = flatten(right);
   
   Node* ans = merge(down, right);
   
   return ans;
}