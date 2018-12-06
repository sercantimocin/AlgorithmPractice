// StacksAndQueues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Node {
public:
	Node(int value)
	{
		data = value;
	}

	int data;
	Node* previous;
};

class Stack {
public:
	Node* top;
	int data;
	void push(int newdata) {
		if (top == NULL)
		{
			top = new Node(newdata);
		}
		else
		{
			Node* node = new Node(newdata);
			node->previous = top;
			top = node;
		}
	}

	int pop() {
		int returnValue = top->data;
		top = top->previous;
		return returnValue;
	}

};

//3 1 Describe how you could use a single array to implement three stacks
class StackUseArray {
	int const stackSize = 300;
	int* arr = new int[stackSize * 3];
	int stackIndexes[3] = { 0,0,0 };

	int getLastIndexForStack(int numStack) {
		return numStack * stackSize + stackIndexes[numStack];
	}

public:

	void push(int numStack, int value) {
		int index = getLastIndexForStack(numStack) + 1;
		stackIndexes[numStack]++;
		arr[index] = value;
	}

	int pop(int numStack) {
		int index = getLastIndexForStack(numStack);
		stackIndexes[numStack]--;
		int temp = arr[index];
		arr[index] = 0;
		return temp;
	}
};

//3.2 How would you design a stack which, in addition to push and pop, 
// also has a function min which returns the minimum element ? 
//Push, pop and min should all operate in O(1) time
class StackWithMin
{
	Node* top;
	Node* minTop;
public:
	StackWithMin()
	{
	}

	void push(int value) {
		if (top == NULL)
		{
			top = new Node(value);
			minTop = new Node(value);
		}
		else
		{
			Node* newNode = new Node(value);
			newNode->previous = top;
			top = newNode;

			int minValue = minTop->data;
			if (minValue > value)
			{
				Node* newMin = new Node(value);
				newMin->previous = minTop;
				minTop = newMin;
			}
		}
	}

	int pop() {
		Node* newTop = top->previous;

		int minValue = minTop->data;
		if (minValue == top->data)
		{
			Node* newMinTop = minTop->previous;
			minTop = newMinTop;
		}

		int result = top->data;
		top = newTop;
		return result;
	}

	int min() {
		return minTop->data;
	}

	int getLastItem() {
		return top->data;
	}
};




int main()
{
	//StackUseArray* stack = new StackUseArray();
	//stack->push(0, 1);
	//stack->push(1, 2);
	//stack->push(2, 3);

	//std::cout << stack->pop(2) << "-" << stack->pop(0) << "-" << stack->pop(1);

	StackWithMin* minStack = new StackWithMin();
	minStack->push(11);
	std::cout << "Min1:" << minStack->min() << "\n";
	minStack->push(7);
	std::cout << "Min2:" << minStack->min() << "\n";
	minStack->pop();
	std::cout << "Min3:" << minStack->min() << "\n";


}
