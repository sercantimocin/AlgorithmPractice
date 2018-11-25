// TreeAndGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>

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

int main()
{
	BTree* root = new BTree(7);
	root->append(5);
	root->append(11);
	root->append(3);
	root->append(8);
	root->append(2);
	root->append(13);

	bool isBalanced = isBalancedTree(root);

	std::cout << "Is Balanced Tree :" << isBalanced << "\n";
}
