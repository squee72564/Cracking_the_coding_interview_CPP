#include "linkedlist.hpp"

#include <cmath>

Node * getIntersecting(Node *l1, Node *l2) {
	if (!l1 || !l2) return nullptr;

	int sz_1 = 1;
	int sz_2 = 1;

	Node *t1 = l1;
	while (t1->next) {
		sz_1++;
		t1 = t1->next;
	}

	Node *t2 = l2;
	while (t2->next) {
		sz_2++;
		t2 = t2->next;
	}

	if (t1 != t2) return nullptr;

	Node *s = (sz_1 < sz_2) ? l1 : l2;
	Node *l = (sz_1 < sz_2) ? l2 : l1;

	for (int i = 0; i < std::abs(sz_1 - sz_2); ++i) {
		l = l->next;
	}

	while (s != l) {
		s = s->next;
		l = l->next;
	}

	return l;

}

int main() {
	Node* l1 = createList({0,1,2,3,2,1,0});
	Node* l2 = createList({9,8,7});

	l2->next->next->next = l1->next->next->next;

	std::cout << "List1:\n";
	printList(l1);

	std::cout << "List2:\n";
	printList(l2);

	Node *intersection = getIntersecting(l1, l2);

	if (intersection) {
		std::cout << "Intersecting node : " << intersection->val << "\n";
	}

	l2->next->next->next = nullptr;

	freeList(l1);
	freeList(l2);

	return 0;
}

