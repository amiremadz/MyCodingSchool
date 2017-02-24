/*
 * mymain.cpp
 *
 *  Created on: Dec 15, 2016
 *      Author: amire
 */

#include "linkedlist.h"

int main(){
	linkedList list1;
	list1.insert(6);
	list1.insert(7);
	list1.insert(8);
	list1.print();
	list1.reverse_iter();
	list1.print();
	list1.reverse_recursive();
	list1.print();
	Node* head = new Node(16);
	linkedList list2(head);
	list2.insert(17);
	list2.print();
	Node* node = new Node(18);
	list2.insert(node);
	list2.print();

	return 0;
}

