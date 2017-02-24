/*
 * bst.h
 *
 *  Created on: Dec 19, 2016
 *      Author: amire
 */

#ifndef BST_H_
#define BST_H_

#include <iostream>

using namespace std;


struct Node{
	Node* left;
	Node* right;
	int data;
	Node(int data): left(nullptr), right(nullptr), data(data){};
};


class bst{
	public:
		bst():root(nullptr){};
		bst(Node* head):root(head){};
		bst(int data){set_root(data);};

	public:
		Node* get_root();
		void set_root(int data);
		void insert(int data);
		void preorder();
		void inorder();
		void postorder();
		int height();
	private:
		Node* root;
		Node* insert_util(Node* head, int data);
		void preorder(Node* head);
		void inorder(Node* head);
		void postorder(Node* head);
		int height_util(Node* head);

};

#endif /* BST_H_ */
