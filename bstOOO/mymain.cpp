/*
 * mymain.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: amire
 */

#include "bst.h"


int main(){
	bst my_bst;
	my_bst.insert(4);
	my_bst.insert(2);
	my_bst.insert(6);
	my_bst.insert(1);
	my_bst.insert(3);
	my_bst.insert(5);
	my_bst.insert(7);
	cout << "preorder: ";
	my_bst.preorder();
	cout << endl;
	cout << "inorder: ";
	my_bst.inorder();
	cout << endl;
	cout << "postorder: ";
	my_bst.postorder();
	cout << endl;
	cout << "root: " << my_bst.get_root()->data << endl;
	cout << "height: " << my_bst.height() << endl;






	return 0;
}


