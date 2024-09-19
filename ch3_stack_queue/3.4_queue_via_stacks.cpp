#include <iostream>
#include <stack>
#include <cassert>

template <typename T>
class MyQueue {
private:
	std::stack<T> stk1;
	std::stack<T> stk2;
	bool isBack;

	void swapStacks() {
		std::stack<T> &empty = (stk1.empty()) ? stk1 : stk2;
		std::stack<T> &full  = (stk1.empty()) ? stk2 : stk1;

		while (!full.empty()) {
			empty.push(full.top());
			full.pop();
		}
		
		isBack = !isBack;
	}

public:
	MyQueue() : isBack(true) {}

	T back() {
		assert(!stk1.empty() || !stk2.empty());

		if (!isBack) {
			swapStacks();
		}

		return stk1.top();

	}

	T front() {
		assert(!stk1.empty() || !stk2.empty());

		if (isBack) {
			swapStacks();
		}

		return stk2.top();
	}

	void push_back(const T& x) {
		if (!isBack) {
			swapStacks();
		}

		stk1.push(x);
	}

	void push_front(const T& x) {

		if (isBack) {
			swapStacks();
		}

		stk2.push(x);
	}

	void pop_back() {
		assert(!stk1.empty() || !stk2.empty());

		if (!isBack) {
			swapStacks();
		}

		stk1.pop();

	}

	void pop_front() {
		assert(!stk1.empty() || !stk2.empty());

		if (isBack) {
			swapStacks();
		}

		stk2.pop();

	}

	bool empty() const {
		return stk1.empty() && stk2.empty();
	}

};


int main() {

	MyQueue<int> mQ;
	
	for (int i = 0; i < 25; ++i) {
		mQ.push_back(i);
		std::cout << mQ.back() << ", ";
	}
	std::cout << std::endl;

	while (!mQ.empty()) {
		std::cout << mQ.front() << ", ";
		mQ.pop_front();
	}
	std::cout << std::endl;

	return 0;
}
