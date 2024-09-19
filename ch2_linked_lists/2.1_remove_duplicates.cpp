#include <iostream>
#include <unordered_set>

#include "linkedlist.hpp"

void removeDuplicates(Node* head) {
	std::unordered_set<int> set;
	Node *prev = nullptr;
	while(head) {
		if (set.find(head->val) != set.end()) {
			prev->next = head->next;
			delete head;
			head = prev;
		} else {
			set.insert(head->val);
			prev = head;
		}

		head = head->next;
	}

}

int main() {
	Node* head = createList({5,6,9,3,6,3,7,2});

	std::cout << "Before:\n";
	printList(head);

	removeDuplicates(head);

	std::cout << "After:\n";
	printList(head);

	freeList(head);
	return 0;
}
