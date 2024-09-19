#ifndef LL_HPP
#define LL_HPP

#include <iostream>
#include <vector>
#include <cassert>

struct Node {
	int val;
	Node *next;

	Node() = default;
	Node(int i) : val(i), next(nullptr) {};
	~Node() = default;
};


Node * createList(std::vector<int>&& vec) {
	assert(vec.size() > 0);

	Node* head = new Node(vec[0]);
	Node* t = head;

	for (int i = 1; i < vec.size(); ++i) {
		t->next = new Node(vec[i]);
		t = t->next;
	}
	
	return head;
}

void printList(Node *head) {
	while (head) {

		if (head->next) {
			std::cout << head->val << "->";
		} else {
			std::cout << head->val;
		}

		head = head->next;
	}
	std::cout << std::endl;
}

void freeList(Node *head) {
	
	while(head) {
		Node * t = head->next;
		delete head;
		head = t;
	}
}

#endif
