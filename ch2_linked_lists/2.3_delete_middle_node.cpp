#include "linkedlist.hpp"

void delete_middle(Node *node) {
	Node *t = node->next;
	node->val = t->val;
	node->next = t->next;
	delete t;

}

int main() {
	Node* head = createList({5,6,9,3,6,3,7,2});

	std::cout << "List:\n";
	printList(head);

	Node *node = head->next->next->next;
	delete_middle(node);

	std::cout << "List:\n";
	printList(head);

	freeList(head);
	return 0;
}

