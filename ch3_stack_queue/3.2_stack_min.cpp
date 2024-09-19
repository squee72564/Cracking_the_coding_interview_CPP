#include <iostream>

#include <cassert>
#include <vector>

struct Rect {
	float width;
	float height;

	bool operator==(const Rect& other) const {
		return (width == other.width && height == other.height);
	}
};


struct RectCompare {
	bool operator()(const Rect& a, const Rect& b) const {
		const float x = a.width * a.height;
		const float y = b.width * b.height;
		return x < y;
	}
};


template <typename T, typename Compare = std::less<T>>
class MinStack {
private:
	std::vector<T> data;
	std::vector<T> _min;
	Compare compare;


public:
	MinStack(Compare comp = Compare()) : compare(comp) {}

	void push(T x) {
		data.push_back(x);
		if (_min.empty() || compare(x, _min.back())) {
			_min.push_back(x);
		}
	}

	T pop() {
		assert(!data.empty());

		T back = data.back();
		data.pop_back ();

		if (_min.back() == back) {
			_min.pop_back();
		}

		return back;
	}

	T min() {
		assert(!_min.empty());
		return _min.back();
	}
};

std::ostream& operator<<(std::ostream& os, const Rect& r) {
	os << "(" << r.width << "," << r.height << ")";
	return os;
}

int main() {
	MinStack<Rect, RectCompare> minStk;

	std::vector<Rect> v = {
		{1.2f, 1.2f},
		{1.5f, 1.5f},
		{2.0f, 2.0f},
		{2.5f, 2.5f},
		{1.0f, 1.0f}
	};

	for (const Rect& r : v) {
		std::cout << r << ", ";
		minStk.push(r);
	}

	std::cout << std::endl;

	Rect min = minStk.min();
	Rect pop = minStk.pop();
	Rect check = (Rect){1.0f, 1.0f};
	Rect check2 = (Rect){1.0f, 1.0f};

	std::cout << "Min : " << min << ", Pop: " << pop << "\n";
	assert(min == check);
	assert(pop == check2);

	min = minStk.min();
	pop = minStk.pop();
	check = (Rect){1.2f, 1.2f};
	check2 = (Rect){2.5f, 2.5f};

	std::cout << "Min : " << min << ", Pop: " << pop << "\n";
	assert(min == check);
	assert(pop == check2);

	min = minStk.min();
	pop = minStk.pop();
	check2 = (Rect){2.0f, 2.0f};

	std::cout << "Min : " << min << ", Pop: " << pop << "\n";
	assert(min == check);
	assert(pop == check2);

	min = minStk.min();
	pop = minStk.pop();
	check2 = (Rect){1.5f, 1.5f};

	std::cout << "Min : " << min << ", Pop: " << pop << "\n";
	assert(min == check);
	assert(pop == check2);

	return 0;
}
