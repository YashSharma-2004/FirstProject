#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int data;
	Node* prev;
	Node* next;
	
	Node(int data) {
		this -> data = data;
		
		this -> next = NULL;
		this -> prev = NULL;
		
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

void printList(Node* &head){
	Node* temp = head;
	if(temp == NULL) {
		cout << "Empty" << endl;
		return;
	}
	cout << "Data: ";
	while(temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

// Lenght

int getLength(Node* &head) {
	
	int lenght = 0;
	
	Node* temp = head;
	while(temp != NULL){
		lenght++;
		temp = temp -> next;
	}
	
	return lenght;
	
}

void insertAtHead(Node* &tail, Node* &head, int data) {
	
	
	if(head == NULL){
		Node* temp = new Node(data);
		
		head = temp;
		tail = temp;
	}
	else {
		Node* temp = new Node(data);
		temp -> next = head;
		
		head -> prev = temp;
		
		head = temp;
	}
}

void insertAtTail(Node* &head,Node* &tail, int data){
	
	if(tail == NULL){
		Node* temp = new Node(data);
		
		tail = temp;
		
		head = temp;
		
	}
	
	
	else{
		
		Node* temp = new Node(data);
		
		tail -> next = temp;
		
		temp -> prev = tail;
		
		tail = temp;
	}
		
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
	
	
	if(position == 1) {
		insertAtHead(tail, head, data);
		return;
	}
	else{
		int cnt = 1;
		
		Node* temp = head;
		
		while(cnt < position - 1) {
			cnt++;
			temp = temp -> next;
		}
		
		if(temp -> next == NULL) {
			insertAtTail(head, tail, data);
			return;
		}
		
		
		else {
			Node* nodeToInsert = new Node(data);
			
			nodeToInsert -> next = temp -> next;
			
			temp -> next = nodeToInsert;
			
			nodeToInsert -> prev = temp;
			
			temp -> next -> prev = nodeToInsert;
			
		}
	}	
}


void deleteNode(Node* &head, int position, Node* &tail) {


	if(position == 1){
		Node* temp = head;

		temp -> next -> prev = NULL;

		head = temp -> next;

		temp -> next = NULL;

		delete temp;

	}


	else {
		int cnt = 1;

		Node* curr = head;
		Node* prev = NULL;

		while(cnt < position) {
			prev = curr;
			curr = curr -> next;
			cnt++;
		}


		if(curr -> next != NULL) {
			
			curr -> prev = NULL;

			prev -> next = curr -> next;

			curr -> next = NULL;
			delete curr;

		}
		else {

			curr -> prev = NULL;
			prev -> next = NULL;
			
			tail = prev;
			delete curr;
		}

	}

}



int main(){
#ifndef YASH_SHARMA
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	

#endif	
	
	Node* node1 = new Node(10);
	
	Node* head = node1;
	Node* tail = node1;
	
	
	printList(head);
	
	cout << "Length Of List:" <<  getLength(head) << endl << endl;
	
	insertAtHead(tail, head, 5);
	printList(head);
	cout << "Length Of List:" <<  getLength(head) << endl << endl;
	
	cout << "Head:->" << head -> data << endl;
	cout << "Tail:->" << tail -> data << endl;
	
	insertAtTail(head, tail, 20);
	printList(head);
	cout << "Length Of List:" <<  getLength(head) << endl << endl;
	
	cout << "Head:->" << head -> data << endl;
	cout << "Tail:->" << tail -> data << endl;
	
	insertAtTail(head, tail, 21);
	printList(head);
	cout << "Length Of List:" <<  getLength(head) << endl << endl;

	cout << "Head:->" << head -> data << endl;
	cout << "Tail:->" << tail -> data << endl;
	
	insertAtTail(head, tail, 22);
	printList(head);
	cout << "Length Of List:" <<  getLength(head) << endl << endl;
	
	cout << "Head:->" << head -> data << endl;
	cout << "Tail:->" << tail -> data << endl;
	
	insertAtPosition(head, tail, 3, 15);
	printList(head);
	cout << "Length Of List:" <<  getLength(head) << endl << endl;
	
	cout << "Head:->" << head -> data << endl;
	cout << "Tail:->" << tail -> data << endl;	
	
	insertAtPosition(head, tail, 1, 0);
	printList(head);
	cout << "Length Of List:" <<  getLength(head) << endl << endl;
	int len = getLength(head);
	
	cout << "Head:->" << head -> data << endl;
	cout << "Tail:->" << tail -> data << endl;
	
	insertAtPosition(head, tail, len + 1, 25);
	printList(head);
	cout << "Length Of List:" <<  getLength(head) << endl << endl;
		
		
	cout << "Head:->" << head -> data << endl;
	cout << "Tail:->" << tail -> data << endl;
	
	// int len1 = getLength(head);
	
	deleteNode(head, 7, tail);
	printList(head);
	cout << "Length Of List:" <<  getLength(head) << endl << endl;
		
	cout << "Head:->" << head -> data << endl;
	cout << "Tail:->" << tail -> data << endl;
	

	return 0;
	
	
	
	
	
	
}








