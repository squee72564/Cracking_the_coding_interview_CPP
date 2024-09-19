#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

template <typename T>
class StackOfStacks {
private:
	std::vector<std::stack<T>> stacks;
	int capacity;
public:
	StackOfStacks(int cap = 10)
		: stacks{std::vector<std::stack<T>>()},
		  capacity(cap) {}
	
	void push(T x) {
		if (stacks.empty() || stacks.back().size() >= capacity) {
			stacks.push_back(std::stack<T>());
		}
		stacks.back().push(x);
	};

	T pop() {
		assert(!stacks.empty() && !stacks.back().empty());

		const T top = stacks.back().top();
		stacks.back().pop();

		if (stacks.back().empty()) {
			stacks.pop_back();
		}
		return top;
	};

	void printStackSizes() const {
		for (const auto& stk : stacks) {
			std::cout << stk.size() << ", ";
		}
		std::cout << std::endl;
	}

	bool empty() const {
		return stacks.empty();
	}
};

int main() {
	StackOfStacks<int> stk;

	for (int i = 0; i < 53; ++i) {
		stk.push(i);
	}

	stk.printStackSizes();

	while (!stk.empty()) {
		std:: cout << stk.pop() << ", ";
	}
	std::cout << std::endl;
	
	return 0;
}
