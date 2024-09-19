#include <random>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

#include "TreeAndGraph.hpp"

TreeNode * minimalTree(std::vector<int>& v, int l, int r) {
	if (l > r) return nullptr;

	const int mid = l + (r-l) / 2;

	return new TreeNode(v[mid], minimalTree(v, l, mid-1), minimalTree(v, mid+1, r));
}

int main() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 9999);
	std::unordered_set<int> set;
	std::vector<int> v;
	v.reserve(32);
	
	for (int i = 0; i < 32; ++i) {
		int n = dis(gen);
		while (set.find(n) != set.end()) {
			n = dis(gen);
		}
		v.push_back(n);
	}

	std::sort(v.begin(), v.end());

	TreeNode *root = minimalTree(v, 0, v.size()-1);

	std::cout << "Tree:\n";
	inorder(root);
	std::cout << std::endl;

	freeBST(root);

	return 0;
}
