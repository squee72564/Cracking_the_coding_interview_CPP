#include "linkedlist.hpp"

Node * kth_to_last(Node* head, int k) {
	Node *lead = head;
	for (int i = 0; i < k; ++i) {
		if (!lead) return nullptr;
		lead = lead->next;
	}

	while (lead) {
		head = head->next;
		lead = lead->next;
	}

	return head;
}

int main() {
	Node* head = createList({5,6,9,3,6,3,7,2});

	std::cout << "List:\n";
	printList(head);

	int k = 1;
	Node *kth = kth_to_last(head, k);

	if (!kth) {
		std::cout << "K out of bounds\n";
		freeList(head);
		return 1;
	}

	std::cout << k << " node from last: " << kth->val << "\n"; 

	freeList(head);
	return 0;
}

