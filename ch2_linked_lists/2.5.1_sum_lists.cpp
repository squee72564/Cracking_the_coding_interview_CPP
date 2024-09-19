#include "linkedlist.hpp"

Node * sumLists(Node *l1, Node *l2) {
	int carry = 0;
	Node *ans = nullptr;

	Node **t = &ans;

	while (l1 || l2 || carry) {
		int a = 0;
		if (l1) {
			a = l1->val;
			l1 = l1->next;
		}

		int b = 0;
		if (l2) {
			b = l2->val;
			l2 = l2->next;
		}

		const int sum = a + b + carry;
		const int rem = sum%10;
		carry = sum/10;

		*t = new Node(rem);
		t = &(*t)->next;

	}

	return ans;
}

int main() {
	Node* l1 = createList({7,1,6});
	Node* l2 = createList({5,9,2});
	std::cout << "List 1:\n";
	printList(l1);
	std::cout << "List 2:\n";
	printList(l2);

	Node* ans = sumLists(l1, l2);
	std::cout << "Sum:\n";
	printList(ans);


	freeList(l1);
	freeList(l2);
	freeList(ans);
	return 0;
}

