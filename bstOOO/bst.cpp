/*
 * bst.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: amire
 */
#include "bst.h"


void bst::set_root(int data){
	root = new Node(data);
}

Node* bst::get_root(){
	return root;
}


void bst::preorder(Node* head){
	if(head == nullptr)
		return;
	cout << head->data << " ";
	preorder(head->left);
	preorder(head->right);
}

void bst::preorder(){
	preorder(root);
}


void bst::inorder(Node* head){
	if(head == nullptr)
		return;
	inorder(head->left);
	cout << head->data << " ";
	inorder(head->right);
}

void bst::inorder(){
	inorder(root);
}

void bst::postorder(Node* head){
	if(head == nullptr)
		return;
	postorder(head->left);
	postorder(head->right);
	cout << head->data << " ";
}

void bst::postorder(){
	postorder(root);
}



Node* bst::insert_util(Node* head, int data){
	if(head == nullptr)
	{
		return new Node(data);
	}

	if(data < head->data){
		head->left = insert_util(head->left, data);
	}
	else{
		head->right = insert_util(head->right, data);
	}
	return head;
}


void bst::insert(int data){
	root = insert_util(root, data);
}

int bst::height(){
	return height_util(root);
}

int bst::height_util(Node* head){
	if(head == nullptr)
		return 0;
	int result;
	int left = height_util(head->left);
	int right = height_util(head->right);
	if(left>right){
		result = 1 + left;
	}
	else{
		result = 1 + right;
	}
	return result;
}










