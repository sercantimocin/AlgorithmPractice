// TreeAndGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <math.h> 

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

	//4.3
	int arr[] = { 1, 3, 5, 7, 9, 11, 13 };

	BTree* root = addToTree(arr, 0, 6);
	root->Traverse(root);
}
