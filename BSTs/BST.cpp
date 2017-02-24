/*
 * BST.cpp
 *
 *  Created on: Dec 13, 2016
 *      Author: amire
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
	Node* left;
	Node* right;
	int data;
};

Node* newNode(const int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

void preorder(const Node* head){
	if(head == nullptr)
		return;
	cout << head->data << " ";
	preorder(head->left);
	preorder(head->right);
}

void inorder(const Node* head){
	if(head == nullptr)
		return;
	inorder(head->left);
	cout << head->data << " ";
	inorder(head->right);
}

void postorder(const Node* head){
	if(head == nullptr)
		return;
	postorder(head->left);
	postorder(head->right);
	cout << head->data << " ";

}

Node* insert(Node* head, const int data){
	if(head == nullptr){
		return newNode(data);
	}
	if(data < head->data){
		head->left = insert(head->left, data);
	}
	else{
		head->right = insert(head->right, data);
	}
	return head;
}

bool isBSTutil(const Node* head, const int min, const int max){
	if(head == nullptr)
		return true;
	if((head->data > min) && (head->data < max))
	{
		bool left = isBSTutil(head->left, min, head->data);
		bool right = isBSTutil(head->right, head->data, max);
		return (left && right);
	}
	return false;
}


int height(const Node* head){
	if(head == nullptr)
		return 0;
	int left = height(head->left);
	int right = height(head->right);
	int result;
	if(left>right)
		result = 1 + left;
	else
		result = 1 + right;
	return result;
}

bool isBST(const Node* head){
	return isBSTutil(head, -1e8, 1e8);
}

int max(const Node* head){
	if(head == nullptr)
		return -1e5;
	int result = head->data;
	int left = max(head->left);
	int right = max(head->right);
	if(left > result)
		result = left;
	if(right > result)
		result = right;
	return result;
}

int min(const Node* head){
	if(head == nullptr)
		return 1e5;
	int result = head->data;
	int left = min(head->left);
	int right = min(head->right);
	if(left < result)
		result = left;
	if(right < result)
		result = right;
	return result;
}

bool isBSTbad(const Node* head){
	if(head == nullptr)
		return true;
	if(max(head->left) > head->data)
		return false;
	if(min(head->right) < head->data)
		return false;
	return isBSTbad(head->left) && isBSTbad(head->right);
}


void topviewleft(const Node* head){
	if(head == nullptr)
		return;
	topviewleft(head->left);
	cout<< head->data << " ";
}

void topviewright(const Node* head){
	if(head == nullptr)
		return;
	cout << head->data << " ";
	topviewright(head->right);
}

void topview(const Node* head){
	if(head == nullptr)
		return;
	topviewleft(head->left);
	cout << head->data << " ";
	topviewright(head->right);
}


void levelorder(Node* head, vector< vector<Node*> > &result){
	if(head == nullptr)
		return;
	queue<Node*> my_q;
	my_q.push(head);

	while(!my_q.empty()){
		int l = my_q.size();
		vector<Node*> level;
		while(l){
			Node* top = my_q.front();
			my_q.pop();
			level.push_back(top);
			if(top->left)
				my_q.push(top->left);
			if(top->right)
				my_q.push(top->right);
			l--;
		}
		result.push_back(level);
	}

}

void print(const vector<Node*> arr){
	for(auto node:arr)
		cout << node->data << " ";
	cout << endl;
}


Node* LCA(Node* head, int v1, int v2){
	if(v1 > v2){
		int tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	if(v1 < head->data && head->data < v2)
		return head;
	Node* result;
	if(v1 < head->data && v2 < head->data)
		result = LCA(head->left, v1, v2);
	else
		result = LCA(head->right, v1, v2);
	return result;
}

void print_level_order(vector<vector<Node*>> result){
	cout << "level order:" << endl;
	for(auto level:result)
		print(level);
}

Node* max_node(Node* root){
	if(root == nullptr)
		return root;
	while(root->right)
		root = root->right;
	return root;
}

Node* min_node(Node* root){
	if(root == nullptr)
		return root;
	while(root->left)
		root = root->left;
	return root;
}

Node* delete_node(Node* root, int data){
	if(root == nullptr)
		return nullptr;
	else if(data > root->data){
			root->right = delete_node(root->right, data);
		}
	else if(data < root->data){
		root->left = delete_node(root->left, data);
	}
	else{
		if(root->left == nullptr && root->right == nullptr){
				free(root);
				root = nullptr;
		}
		else if(root->left == nullptr){

			Node* tmp = root;
			root = root->right;
			free(tmp);
		}
		else if(root->right == nullptr){
			Node* tmp = root;
			root = root->left;
			free(tmp);
		}
		else{
			//Node* max_left = max_node(root->left);
			//root->data = max_left->data;
			//root->left = delete_node(root->left, max_left->data);

			Node* min_right = min_node(root->right);
			root->data = min_right->data;
			root->right = delete_node(root->right, min_right->data);

		}
	}

	return root;
}

Node* find(Node* root, int value){
	if(root == nullptr)
		return nullptr;
	Node* result;
	if(root->data == value)
		result = root;
	else if(value < root->data)
		return find(root->left, value);
	else
		return find(root->right, value);
	return result;

}

Node* inorder_successor(Node* root, int value){
	Node* node = find(root, value);
	if(node == nullptr)
		return nullptr;
	Node* result = nullptr;
	if(node->right)
		result = min_node(node->right);
	else{
		while(root->data != value){
			if(value < root->data){
				result = root;
				root = root->left;
			}
			else{
				root = root->right;
			}
		}
	}
	return result;
}

Node* inorder_predecessor(Node* root, int value){
	if(root == nullptr)
		return nullptr;
	Node* node = find(root, value);
	Node* result = nullptr;
	if(node->left){
		result = max_node(node->left);
	}
	else{
		while(root->data != value){
			if(root->data > value){
				root = root->left;
			}
			else if(root->data < value){
				result = root;
				root = root->right;
			}
		}
	}
	return result;
}


int main(){
	Node* head = nullptr;
	head = insert(head, 4);
	head = insert(head, 2);
	head = insert(head, 6);
	head = insert(head, 1);
	head = insert(head, 3);
	head = insert(head, 5);
	head = insert(head, 7);
	cout << "inorder: ";
	inorder(head);
	cout << endl;
	cout << "preorder: ";
	preorder(head);
	cout << endl;
	cout << "postorder: ";
	postorder(head);
	cout << endl;
	cout << "height: " << height(head) << endl;


	if(isBSTbad(head))
		cout << "it is BST!" << endl;
	else
		cout << "it is NOT BST!" << endl;
	if(isBST(head))
		cout << "it is BST!" << endl;
	else
		cout << "it is NOT BST!" << endl;
	cout << "max: " << max(head) << endl;
	cout << "min: " << min(head) << endl;
	cout << "topview: ";
	topview(head);
	cout << endl;
	Node* head2 = newNode(4);
	head2->left = newNode(10);
	head2->right = newNode(20);
	cout << "inorder: ";
	inorder(head2);
	cout << endl;
	if(isBST(head2))
		cout << "it is BST!" << endl;
	else
		cout << "it is NOT BST!" << endl;

	vector< vector<Node*> > result;
	levelorder(head, result);
	print_level_order(result);

	int v1, v2;
	v1 = 5;
	v2 = 1;
	Node* lca = LCA(head, v1, v2);
	cout << "LCA between " << v1 << " and " << v2 << ": " << lca->data << endl;
	Node* head3 = nullptr;
	head3 = insert(head3, 12);
	head3 = insert(head3, 5);
	head3 = insert(head3, 15);
	head3 = insert(head3, 3);
	head3 = insert(head3, 7);
	head3 = insert(head3, 13);
	head3 = insert(head3, 17);
	head3 = insert(head3, 1);
	head3 = insert(head3, 9);
	inorder(head3);
	cout << endl;
	result.clear();
	levelorder(head3, result);
	print_level_order(result);
	head3 = delete_node(head3, 1);
	cout << "inorder: ";
	inorder(head3);
	cout << head3->data << endl;
	result.clear();
	levelorder(head3, result);
	print_level_order(result);

	Node* head4 = nullptr;
	head4 = insert(head4, 15);
	head4 = insert(head4, 10);
	head4 = insert(head4, 20);
	head4 = insert(head4, 8);
	head4 = insert(head4, 12);
	head4 = insert(head4, 17);
	head4 = insert(head4, 25);
	head4 = insert(head4, 6);
	head4 = insert(head4, 11);
	head4 = insert(head4, 16);
	head4 = insert(head4, 27);
	result.clear();
	levelorder(head4, result);
	print_level_order(result);
	int value = 6;
	Node* successor = inorder_successor(head4, value);
	if(successor)
		cout << "Inorder successor for " << value << ": " << successor->data << endl;
	else
		cout << "There is no inorder successor for " << value << endl;
	Node* predecessor = inorder_predecessor(head4, value);
	if(predecessor)
		cout << "Inorder predecessor for " << value << ": " << predecessor->data << endl;
	else
		cout << "There is no inorder predecessor for " << value << endl;
	return 0;
}





