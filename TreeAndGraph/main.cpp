// TreeAndGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <math.h> 
#include <list>

class Node {
public:
	Node(int val)
	{
		value = val;
	}

	int value;
	Node* left;
	Node* right;
	Node* parent;
};


class BTree {

private:
	int value;


public:
	BTree(int val)
	{
		value = val;
	}

	int getValue() {
		return value;
	}

	BTree* getRightNode() {
		return right;
	}

	BTree * getLeftNode() {
		return left;
	}

	BTree * left;
	BTree * right;


	void append(int val) {
		BTree* current = this;

		while (current != NULL)
		{
			if (current->value > val)
			{
				if (current->left == NULL)
				{
					current->left = new BTree(val);
					return;
				}
				else
				{
					current = current->left;
				}
			}

			if (current->value < val)
			{
				if (current->right == NULL)
				{
					current->right = new BTree(val);
					return;
				}
				else
				{
					current = current->right;
				}
			}
		}
	}

	void Traverse(BTree * root) {
		if (root == NULL)
		{
			return;
		}

		std::cout << root->getValue() << "\n";
		Traverse(root->left);
		Traverse(root->right);
	}

};

int minDepth(BTree *root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + std::min(minDepth(root->getLeftNode()), minDepth(root->getRightNode()));
}

int maxDepth(BTree * root) {
	if (root == NULL)
	{
		return 0;
	}

	return 1 + std::max(maxDepth(root->getLeftNode()), maxDepth(root->getRightNode()));
}

//4.1 Implement a function to check if a tree is balanced For the purposes of this question,
// a balanced tree is defned to be a tree such that no two leaf nodes diﬀer in distance
// from the root by more than one
bool isBalancedTree(BTree * root) {
	if (root == NULL)
	{
		return false;
	}

	int minD = minDepth(root);
	int maxD = maxDepth(root);

	return maxD - minD < 2;
}

// 4.2 Given a directed graph, design an algorithm to fnd out whether there is a route between two nodes

//TODO graphs

// 4 3 Given a sorted(increasing order) array, write an algorithm to create a binary tree with minimal height
BTree* addToTree(int arr[], int start, int end) {

	if (end < start)
	{
		return NULL;
	}

	BTree * root;

	int mid = round(start + end) / 2;
	BTree * newNode = new BTree(arr[mid]);
	newNode->left = addToTree(arr, start, mid - 1);
	newNode->right = addToTree(arr, mid + 1, end);

	return newNode;
}

// 4.4 Given a binary search tree, design an algorithm which creates a linked list of all the
// nodes at each depth(eg, if you have a tree with depth D, you’ll have D linked lists)
std::list<std::list<BTree*>> createLinklistsAccordingtoDepth(BTree * root) {

	std::list<std::list<BTree*>> arr;

	if (root == NULL)
	{
		return arr;
	}

	int level = 0;


	std::list<BTree*> first;
	first.push_front(root);
	arr.push_front(first);

	while (true)
	{
		std::list<BTree*> tempList;

		std::list<std::list<BTree*>>::iterator itOfArr = arr.begin();
		std::advance(itOfArr, level);

		std::list<BTree*> levelItemOfArr = *itOfArr;

		for (std::list<BTree*>::iterator it = levelItemOfArr.begin(); it != levelItemOfArr.end(); ++it) {

			BTree* node = *it;

			if (node != NULL)
			{
				tempList.push_back(node->left);
				tempList.push_back(node->right);
			}
		}

		if (tempList.size() > 0)
		{
			arr.push_back(tempList);
		}
		else
		{
			break;
		}

		level++;

		return arr;
	}
}


//4 5 Write an algorithm to fnd the ‘next’ node(e g, in - order successor) of a given node in
//a binary search tree where each node has a link to its parent
Node* findInOrderSuccessor(Node* node) {

	if (node == NULL)
	{
		return NULL;
	}

	if (node->right == NULL)
	{
		Node * parent = node->parent;

		while  (node->value > parent->value)
		{
			parent = parent->parent;
		}

		return parent;
	}
	else
	{
		Node* current = node->right;
		Node* parent = node->right;

		while (current != NULL)
		{
			parent = current->parent;
			current = current->left;
		}

		return parent;
	}
}


int main()
{
	//4.1
	//BTree* root = new BTree(7);
	//root->append(5);
	//root->append(11);
	//root->append(3);
	//root->append(8);
	//root->append(2);
	//root->append(13);

	//bool isBalanced = isBalancedTree(root);
	//std::cout << "Is Balanced Tree :" << isBalanced << "\n";
	//------------------------------------------------------------------------------------------

	//4.3
	//int arr[] = { 1, 3, 5, 7, 9, 11, 13 };

	//BTree* root = addToTree(arr, 0, 6);
	//root->Traverse(root);

	//4.4
	//BTree* root = new BTree(5);
	//root->append(3);
	//root->append(7);

	//std::list<std::list<BTree*>> arr = createLinklistsAccordingtoDepth(root);

	//for (std::list<std::list<BTree*>>::iterator itOfArr = arr.begin(); itOfArr != arr.end(); ++itOfArr)
	//{
	//	std::list<BTree*> list = *itOfArr;
	//	for (std::list<BTree*>::iterator it = list.begin(); it != list.end(); ++it)
	//	{
	//		BTree * node = *it;
	//		std::cout << node->getValue();
	//		std::cout << "--";
	//	}

	//	std::cout << "\n";
	//}

	//4.5 
	Node* root = new Node(20);

	root->right = new Node(22);
	root->right->parent = root;

	root->left = new Node(8);
	root->left->parent = root; 

	root->left->left = new Node(4);
	root->left->left->parent = root->left;

	root->left->right = new Node(12);
	root->left->right->parent = root->left;

	root->left->right->left = new Node(10);
	root->left->right->left->parent = root->left->right;

	root->left->right->right = new Node(14);
	root->left->right->right->parent = root->left->right;

	//Node* inOrderSuccessor = findInOrderSuccessor(root);    //Case1 ok
	//Node* inOrderSuccessor = findInOrderSuccessor(root->left); //Case2 ok
	//Node* inOrderSuccessor = findInOrderSuccessor(root->left->right->left); //Case3 ok
	Node* inOrderSuccessor = findInOrderSuccessor(root->left->right->right); //Case4  ok

	std::cout << inOrderSuccessor->value;
}
