#include "linkedlist.hpp"

Node * partition(Node *head, int val) {
	Node *l_head = nullptr, *l_tail = nullptr;
	Node *r_head = nullptr, *r_tail = nullptr;

	while (head) {
		if (head->val < val) {
			if (!l_head) {
				l_head = head;
				l_tail = head;
			} else {
				l_tail->next = head;
				l_tail = l_tail->next;
			}
		} else { 
			if (!r_head) {
				r_head = head;
				r_tail = head;
			} else {
				r_tail->next = head;
				r_tail = r_tail->next;
			}
		}

		head = head->next;
	}

	if (!l_head) {
		return r_head;
	}

	l_tail->next = r_head;

	return l_head;
}

Node * partition2(Node *node, int val) {
	Node* head = node;
	Node* tail = node;

	while (node) {
		Node* next = node->next;
		if (node->val < val) {
			node->next = head;
			head = node;
		} else {
			tail->next = node;
			tail = node;
		}
		node = next;
	}

	tail->next = nullptr;

	return head;

}

int main() {
	Node* head = createList({5,6,9,3,6,3,7,2});

	std::cout << "List:\n";
	printList(head);

	head = partition2(head, 5);

	std::cout << "List:\n";
	printList(head);

	freeList(head);
	return 0;
}

