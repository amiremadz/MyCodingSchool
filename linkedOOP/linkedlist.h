/*
 * linkedlist.h
 *
 *  Created on: Dec 15, 2016
 *      Author: amire
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int data):data(data), next(nullptr){};
};

class linkedList{
	public:
		linkedList():head(nullptr){};
		linkedList(Node* head):head(head){};
		Node* get_head();
		void set_head(int data);
		void insert(int data);
		void insert(Node* node);
		void print();
		void reverse_iter();
		void reverse_recursive();

	private:
		Node* head;
		void reverse_recursive(Node* node);


};


#endif /* LINKEDLIST_H_ */
