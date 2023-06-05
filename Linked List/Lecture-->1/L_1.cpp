#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	
	int data;
	Node* next;
	
	Node(int data){
		this -> data = data;
		this -> next = NULL;
	}
	
	
	~Node(){
		int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            
            this->next = NULL; 
            
        }	
    	cout << "Memory Free. We have deleted: - " << value << endl;		
	}
	
	
};

void printTheLinkedList(Node* head){
	
	Node* temp = head;
	cout << "Data->";
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	
	cout << endl;
}

// To insert at front
// Took refrence because of not creating the copy of that node
void insertAtHead(Node* &head, int data){
	
	Node* temp = new Node(data);
	
	temp -> next = head;
	
	head = temp;
}

// To Insert At end
void insertAtTail(Node* &tail, int data){
	
	Node* temp = new Node(data);
	
	tail -> next = temp;
	
	tail = tail -> next;
	
	
}

void insertAtPosition(Node* &tail, int position, Node* &head, int data) {
	
	if(position == 1){
		insertAtHead(head, data);
		return;
	}
	
	Node* temp = head;
	
	int cnt = 1;
	
	while(cnt < position - 1){
		temp = temp -> next;
		cnt++;
	}
	
	if(temp -> next == NULL){
		insertAtTail(tail, data);
		return;
	}
	
	Node* nodeInsert = new Node(data);
	
	nodeInsert -> next = temp -> next;
	
	temp -> next = nodeInsert;
}

void deleteNode(Node* &head, int position, Node* &tail){
	
	// For deleting the first node
	if(position == 1) {
		
		Node* temp = head;
		
		head = head -> next;
		
		temp -> next = NULL;
		delete temp;
	}
	
	else{
		// For Deleting the middle or the last node
		int cnt = 1;
		
		Node* curr = head;
		Node* prev = NULL;
		
		while(cnt < position){
			prev = curr; 
			curr = curr -> next;
			cnt++;
		}
		
		prev -> next = curr -> next;
		
		 if(curr->next==NULL){
            prev->next = curr->next;
            tail = prev;
        }
        
        else{
            prev->next = curr->next;	
        }
        
		curr -> next = NULL;
		
		delete curr;	
	}
	
}
int main(){
#ifndef Yash_Sharma
	
	freopen("int.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

#endif
	
	Node* node1 = new Node(10);
	
	Node* head = node1;
	
	Node* tail = node1;
	printTheLinkedList(head);
	
	insertAtHead(head, 0);
	printTheLinkedList(head);
	
	
	insertAtTail(tail, 12);
	printTheLinkedList(head);
	cout << endl;
	
	insertAtTail(tail, 15);
	printTheLinkedList(head);
	cout << endl;
	
	insertAtPosition(tail, 4, head, 22);
	printTheLinkedList(head);
	cout << endl;
	
	deleteNode(head, 4, tail);
	printTheLinkedList(head);
	cout << endl;
	
	cout << "head: ->" << head -> data << " Tail: ->" << tail -> data << endl; 
	
	return 0;
	
}