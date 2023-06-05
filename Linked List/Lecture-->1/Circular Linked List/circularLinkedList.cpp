#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int data;
	Node* next;
	
	Node(int d) {
		this -> data = d;
		
		this -> next = NULL;
	}
	
	~Node() {
		
		int val = this -> data;

		if(next != NULL) {
			delete next;
			next = NULL;
		}
		cout << "Memory Free for data:->" << val << endl;
	}
	
};

// Traversing

void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 
// Lenght




void insertNode(Node* &tail, int element, int d) {
    

    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}    

void deleteNode(Node* &tail, int element) {

	if(tail == NULL) {
		cout << "Empty List" << endl;
		return;
	}

	else {
		Node* prev = tail;
		Node* curr = prev -> next;
		
		
        while(curr->data != element) {
			prev = curr;
            curr = curr -> next;
        }

		prev -> next = curr -> next;
		
		// If there are only node then point tail to the null
		if(curr == prev) {
			tail = NULL;
			return;
		}

		// Agar tail is pointing to the curr then point to pre
		if(tail == curr) {
			tail = prev;
		}
		curr -> next = NULL;

		delete curr;
	}
}



int main(){
#ifndef YASH_SHARMA
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	

#endif	
	
	Node* node1 = NULL;
	Node* head = node1;
	
	insertNode(head, 10, 15);
	print(head);

	insertNode(head, 15, 5);
	print(head);	

	deleteNode(head, 15);
	print(head);

	return 0;
}








