// StacksAndQueues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>7
#include <vector>

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
class StackWithMin :public Stack
{
	Stack* minStack;
public:
	StackWithMin()
	{
	}

	void push(int value) {

		Stack::push(value);

		if (minStack == NULL)
		{
			minStack = new Stack();
			minStack->push(value);
		}
		else
		{
			int minValue = minStack->top->data;
			if (minValue > value)
			{
				minStack->push(value);
			}
		}
	}

	int pop() {
		int result = Stack::pop();

		int minValue = minStack->top->data;
		if (minValue == result)
		{
			minStack->pop();
		}

		return result;
	}

	int min() {
		return minStack->top->data;
	}

	int getLastItem() {
		return top->data;
	}
};


//3 3 Imagine a (literal) stack of plates If the stack gets too high, it might topple Therefore, in real life, we would likely start a new stack when the previous stack exceeds
//some threshold Implement a data structure SetOfStacks that mimics this SetOfStacks should be composed of several stacks, and should create a new stack once
//the previous one exceeds capacity SetOfStacks push() and SetOfStacks pop() should behave identically to a single stack(that is, pop() should return the same values as it
//would if there were just a single stack)
//FOLLOW UP
//Implement a function popAt(int index) which performs a pop operation on a specifc sub - stack
class SetOfStacks {
	std::vector<Stack> stackArr;
	int dataCount = 0;
	int capacityForPerStack;

private:
	Stack getCurrentStack() {
		int stackIndex = dataCount / capacityForPerStack;

		int diff = stackArr.size() - 1 - stackIndex;

		if (diff == -1)
		{
			stackArr.push_back(*new Stack());
			diff++;
		}

		if (diff >= 0)
		{
			return stackArr[stackIndex];
		}

		throw _STDEXCEPT_;
	}

public:
	SetOfStacks(int maxCapacity)
	{
		capacityForPerStack = maxCapacity;
	}

	void push(int value) {
		Stack stack = getCurrentStack();
		stack.push(value);
		dataCount++;
	}

	int pop() {
		Stack stack = getCurrentStack();
		int result = stack.pop();
		dataCount--;
		return result;
	}

	int popAt(int index) {
		return stackArr.at(index).pop();
	}
};


int main()
{
	//StackUseArray* stack = new StackUseArray();
	//stack->push(0, 1);
	//stack->push(1, 2);
	//stack->push(2, 3);

	//std::cout << stack->pop(2) << "-" << stack->pop(0) << "-" << stack->pop(1);

	//----------------------------------------------------------

	//StackWithMin* minStack = new StackWithMin();
	//minStack->push(11);
	//std::cout << "Min1:" << minStack->min() << "\n";
	//minStack->push(7);
	//std::cout << "Min2:" << minStack->min() << "\n";
	//minStack->pop();
	//std::cout << "Min3:" << minStack->min() << "\n";

	//-----------------------------------------------------------

	SetOfStacks* setOfStacks = new SetOfStacks(1);
	setOfStacks->push(1);
	setOfStacks->push(2);
	setOfStacks->push(3);
	setOfStacks->popAt(1);

	std::cout << setOfStacks->pop();

}
