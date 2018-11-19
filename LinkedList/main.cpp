// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
	int data;
	Node * next;
	Node * previous;

	Node(int data)
	{
		this->data = data;
	}

	void addNext(int data) {
		Node * last = getLastNode();

		Node * newNode = new Node(data);
		last->next = newNode;
	}

	void addBefore(int data) {
		Node * newNode = new Node(data);
		this->previous = newNode;
	}

	Node* getLastNode() {
		Node * current = this;
		Node * previous = this;

		while (current != NULL)
		{
			previous = current;
			current = current->next;

		}

		return previous;
	}

	void visitNextAll() {
		Node * current = this;

		while (current != NULL)
		{
			std::cout << current->data;
			std::cout << "-";
			current = current->next;
		}
	}
};


//2.1 Write code to remove duplicates from an unsorted linked list
//FOLLOW UP
//How would you solve this problem if a temporary buﬀer is not allowed ?
void removeDublicateItemsInLinklist(Node * head)
{
	std::unordered_map<int, bool> map;

	Node* current = head;
	Node* previous = head;

	while (current != NULL)
	{
		if (map[current->data]) {
			previous->next = current->next;
		}
		else {
			previous = current;
			map[current->data] = true;
		}

		current = current->next;
	}
}

void removeDublicateItemsWithoutBufferInLinklist(Node * head) {
	Node * searchedNode = head;
	Node * visitorPointer = head->next;
	Node*  visitorPreviousPointer = head;

	while (searchedNode != NULL)
	{
		while (visitorPointer != NULL)
		{
			if (searchedNode->data == visitorPointer->data)
			{
				visitorPreviousPointer->next = visitorPointer->next;
			}

			visitorPreviousPointer = visitorPointer;
			visitorPointer = visitorPointer->next;
		}

		searchedNode = searchedNode->next;
		visitorPreviousPointer = searchedNode;

		if (searchedNode != NULL)
		{
			visitorPointer = searchedNode->next;
		}
	}
}

//2.2 Implement an algorithm to find the nth to last element of a singly linked list
int findN2Last(Node* head) {
	int count = 1;

	Node* current = head;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}

	int countOfCombination = 1;

	for (int i = 2; i < count; i++)
	{
		countOfCombination *= i;
	}

	return countOfCombination;
}

//2.3 Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node
void removeNode(Node * head, int deleteVal) {

	Node * current = head;
	Node * previous = head;

	while (current != NULL)
	{
		if (current->data == deleteVal)
		{
			previous->next = current->next;
		}

		previous = current;
		current = current->next;

	}
}

// 2.4 You have two numbers represented by a linked list, where each node contains a single digit The digits are stored in reverse order, 
// such that the 1’s digit is at the head of the list Write a function that adds the two numbers and returns the sum as a linked list
Node * sumTwoLinklist(Node * firstNumberHead, Node * secondNumberHead) {

	Node * firstPtr = firstNumberHead;
	Node * secondPtr = secondNumberHead;

	int remainder = 0;

	while (firstPtr != NULL && secondPtr != NULL)
	{
		int sumOfDigit = firstPtr->data + secondPtr->data;

		firstPtr->data = remainder +(sumOfDigit % 10);
		remainder = sumOfDigit / 10;

		secondPtr = secondPtr->next;
		firstPtr = firstPtr->next;
	}

	return firstNumberHead;
}


int main()
{
	//Node * head = new Node(5);
	//head->addNext(7);
	//head->addNext(19);
	//head->addNext(9);
	//head->addNext(7);

	//removeDublicateItemsInLinklist(head);

	//2.1.a
	//-----------------------------------------------------------------------------

	//Node * head = new Node(5);
	//head->addNext(7);
	//head->addNext(19);
	//head->addNext(9);
	//head->addNext(7);
	//head->addNext(9);

	//removeDublicateItemsWithoutBufferInLinklist(head);

	//head->visitNextAll();

	//2.1.b
	//--------------------------------------------------------------------------------

	//Node * head = new Node(5);
	//head->addNext(7);
	//head->addNext(19);
	//head->addNext(9);
	//head->addNext(7);
	//head->addNext(9);

	//int count = findN2Last(head);
	//std::cout << "\nCombination count :";
	//std::cout << count;

	// 2.2
	//-------------------------------------------------------------------------------

	//Node * head2 = new Node(1);
	//head2->addNext(2);
	//head2->addNext(3);
	//head2->addNext(4);
	//head2->addNext(5);

	//int val = 3;

	//removeNode(head2, val);

	//std::cout << "\n After remove node :";
	//head2->visitNextAll();

	// 2.3
	//-------------------------------------------------------------------------------

	Node * head = new Node(3);
	head->addNext(1);
	head->addNext(5);

	Node * head2 = new Node(5);
	head2->addNext(9);
	head2->addNext(2);

	sumTwoLinklist(head, head2);

	std::cout << "\n After sum nodes :";
	head->visitNextAll();

	cin.get();
	return 0;
}
