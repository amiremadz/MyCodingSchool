/*
 * linkedlist.cpp
 *
 *  Created on: Dec 15, 2016
 *      Author: amire
 */
#include "linkedlist.h"



Node* linkedList::get_head(){
	return head;
}

void linkedList::set_head(int data){
	head = new Node(data);
}

void linkedList::insert(int data){
	if(head == nullptr){
		set_head(data);
		return;
	}
	Node* newnode = new Node(data);
	Node* node = head;
	while(node->next)
		node = node->next;
	node->next = newnode;

}


void linkedList::insert(Node* node){
	if(head == nullptr){
		head = node;
		return;
	}
	Node* tmp = head;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}


void linkedList::print(){
	Node* node = head;
	while(node){
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}


void linkedList::reverse_iter(){
	if(head == nullptr || head->next == nullptr)
		return;
	Node* prev = nullptr;
	Node* cur = head;
	Node* tmp;

	while(cur){
		tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	head = prev;
}

void linkedList::reverse_recursive(){
	reverse_recursive(head);
}

void linkedList::reverse_recursive(Node* node){
	if(node == nullptr || node->next == nullptr){
		head = node;
		return;
	}

	Node* rest = node->next;
	head = rest;
	reverse_recursive(rest);
	node->next->next = node;
	node->next = nullptr;
}


