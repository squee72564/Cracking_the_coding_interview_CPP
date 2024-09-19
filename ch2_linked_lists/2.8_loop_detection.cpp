#include "linkedlist.hpp"

Node * loopDetection(Node* node) {
	Node *fast = node;
	Node *slow = node;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}

	if (!fast || !fast->next) return nullptr;

	slow = node;
	while (slow != fast) {
		fast = fast->next;
		slow = slow->next;
	}

	return fast;
}

int main() {
	Node* l1 = createList({0,1,2,3,4,5,6,7,8,9,10,11,12,13,14});
	
	Node* last = l1;
	while (last->next) {
		last = last->next;
	}

	last->next = l1->next->next->next->next->next->next->next->next->next->next;

	std::cout << "Expected loop start : " << last->next->val << "\n";
	
	Node *loopStart = loopDetection(l1);

	std::cout << "Found loop start : " << loopStart->val << "\n";

	last->next = nullptr;
	freeList(l1);

	return 0;
}

