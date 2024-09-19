#include "linkedlist.hpp"

#include <stack>

bool isPalindrome(Node *head) {
	int n = 0;

	Node *t = head;
	while(t) {
		n++;
		t = t->next;
	}

	int half = n/2;

	std::stack<int> stk;
	t = head;
	for (int i = 0; i < half; ++i) {
		stk.push(t->val);
		t = t->next;
	}

	if (n%2 != 0) t = t->next;

	while (t) {
		if (t->val != stk.top()) return false;

		stk.pop();

		t = t->next;
	}

	return true;
}

int main() {
	Node* head = createList({0,1,2,3,2,1,0});

	std::cout << "List:\n";
	printList(head);

	if(isPalindrome(head)) {
		std::cout << "Is planindrome\n";
	}

	freeList(head);

	head = createList({0,1,2,3,4,5,6});

	std::cout << "List:\n";
	printList(head);

	if(isPalindrome(head)) {
		std::cout << "Is planindrome\n";
	}

	freeList(head);
	return 0;
}

