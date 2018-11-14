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
void cleanUpLinkList(Node * head)
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



int main()
{
	Node * head = new Node(5);
	head->addNext(7);
	head->addNext(19);
	head->addNext(9);
	head->addNext(7);

	cleanUpLinkList(head);

	head->visitNextAll();

	cin.get();
	return 0;
}
