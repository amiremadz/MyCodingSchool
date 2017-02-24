#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
using namespace std;

struct Node{
	Node* next;
	int data;
};


Node* newNode(int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data= data;
	node->next = nullptr;
	return node;
}

Node* insert(Node* head, int data){
	if(head == nullptr)
		return newNode(data);
	Node* cur = head;
	while(cur->next)
		cur = cur->next;
	cur->next = newNode(data);
	return head;
}

void print(Node* head){
	while(head){
		cout << setw(5) << head->data;
		head = head->next;
	}
	cout << endl;
}

Node* reverse_iter(Node* head){
	if(head == nullptr || head->next == nullptr)
		return head;
	Node* prev = nullptr;
	Node* cur = head;
	Node* tmp;

	while(cur){
		tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	return prev;

}

Node* reverse_recursive(Node* head){
	if(head == nullptr || head->next == nullptr)
		return head;
	Node* rest = head->next;
	rest = reverse_recursive(rest);
	head->next->next = head;
	head->next = nullptr;
	return rest;
}

Node* reverse_stack(Node* head){
	if(head == nullptr || head->next == nullptr)
		return head;
	stack<Node*> mystack;
	while(head){
		mystack.push(head);
		head = head->next;
	}
	head = mystack.top();
	mystack.pop();
	Node* node = head;
	while(!mystack.empty()){
		node->next = mystack.top();
		node = node->next;
		mystack.pop();
	}
	node->next = nullptr;
	return head;

}


void print_forward_recursive(Node* head){
	if(head == nullptr){
		cout << endl;
		return;
	}
	cout << setw(5) << head->data;
	print_forward_recursive(head->next);
}

void print_backward_recursive(Node* head){
	if(head == nullptr){
		return;
	}
	print_backward_recursive(head->next);
	cout << setw(5) << head->data;
}

void populate_list(Node* head, const vector<Node*> arr){
	int n = arr.size();
	Node* node = head;
	for(int i=1; i<n-1; i++){
		node->next = arr[i];
		node = node->next;
	}
}
int length(const Node* head){
	int l = 0;
	while(head){
		l++;
		head = head->next;
	}
	return l;
}
Node* find_mergepoint(Node* head1, Node* head2){
	int l1 = length(head1);
	int l2 = length(head2);
	int d = l1 - l2;
	if(l1 < l2){
		Node* tmp = head1;
		head1 = head2;
		head2 = tmp;
		d = -d;
	}
	while(d--){
		head1 = head1->next;
	}

	while(head1 != head2){
		head1 = head1->next;
		head2 = head2->next;
	}
	return head1;

}

Node* insert_node(Node* head, Node* node){
	if(head == nullptr)
		return node;
	Node* tmp = head;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return head;
}

Node* merge(Node* head1, Node* head2){
	if(head1 == nullptr)
		return head2;
	if(head2 == nullptr)
		return head1;
	Node* newhead;

	if(head1->data < head2->data){
		newhead = head1;
		head1->next = merge(head1->next, head2);
	}
	else{
		newhead = head2;
		head2->next = merge(head2->next, head1);
	}
	return newhead;

}

int main(){
	Node* head = nullptr;
	const int n = 7;
	vector<Node*> arr;
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 4);
	print(head);
	head = reverse_iter(head);
	print(head);
	head = reverse_recursive(head);
	print_forward_recursive(head);
	head = reverse_stack(head);
	print(head);

	//print_backward_recursive(head);
	//cout << endl;
	//print_backward_recursive(head);

	for(int i=0; i<n; i++)
		arr.push_back(newNode(i));

	Node* head1 = arr[0];
	Node* head2 = newNode(10);
	head2 = insert(head2, 11);
	head2 = insert_node(head2, arr[4]);
	populate_list(head1, arr);
	print(head1);
	print(head2);
	Node* mergepoint;
	mergepoint = find_mergepoint(head1,  head2);
	cout << mergepoint->data << endl;

	Node* head3 = nullptr;
	Node* head4 = nullptr;

	head3 = insert(head3, 3);
	head3 = insert(head3, 7);
	head3 = insert(head3, 10);
	head3 = insert(head3, 16);

	head4 = insert(head4, 5);
	head4 = insert(head4, 8);
	head4 = insert(head4, 14);

	cout << "list 1: ";
	print(head3);
	cout << endl;
	cout << "list 2: ";
	print(head4);
	cout << endl;

	Node* newhead = (Node*) malloc(sizeof(Node));
	newhead = merge(head3, head4);
	cout << "merge 2 lists:" << endl;
	print(newhead);



	return 0;
}

