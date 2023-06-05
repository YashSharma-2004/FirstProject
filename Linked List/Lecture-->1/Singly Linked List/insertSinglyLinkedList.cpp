#include <bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node* next;
	
	Node(int data){
		this -> data = data;
		this -> next = NULL;
	}
	
};

void printTheList(Node* head) {
	
	Node* temp = head;
	
	while(temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

void insertAtHead(Node* &head, int data){
	
	Node* temp = new Node(data);
	
	temp -> next = head;
	
	head = temp;
	
}
void insertAtTail(Node* &Tail, int data) {
	
	Node* temp = new Node(data);
	
	Tail -> next = temp;
	
	Tail = Tail -> next;
	
}

void insertAtPosition(int position, int data, Node* &head, Node* &tail) {
	if(position == 1){
		insertAtHead(head, data);
		return;
	}
	else {
		int cnt = 1;
		
		Node* temp = head;
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
}
int main(){
	
	Node* node1 = new Node(1);
	
	Node* head = node1;
	Node* tail = node1;
	
	insertAtHead(head, 0);
	printTheList(head);
	
	insertAtTail(tail, 3);
	printTheList(head);
	
	insertAtPosition(3, 2, head, tail);
	printTheList(head);
	
	return 0;
	
}