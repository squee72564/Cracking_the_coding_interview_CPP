#include <algorithm>
#include <iostream>
#include <limits.h>

#include "TreeAndGraph.hpp"

static TreeNode * minimalTree(const std::vector<int>& v, int l, int r) {
	if (l > r) return nullptr;

	const int mid = l + (r-l) / 2;

	return new TreeNode(v[mid], minimalTree(v, l, mid-1), minimalTree(v, mid+1, r));
}

int dfs(TreeNode* root) {
	if (!root) return -1;

	int l = dfs(root->left);
	if (l == INT_MIN) return INT_MIN;

	int r = dfs(root->right);
	if (r == INT_MIN) return INT_MIN;

	int diff = std::abs(l - r);

	return (diff > 1) ? INT_MIN : std::max(l, r)+ 1;
}

bool isBalanced(TreeNode *root) {
	return dfs(root) != INT_MIN;
}

int main() {
	TreeNode* root = createBST({0,1,2,3,4,5,6,7});
	inorder(root);
	std::cout << std::endl;
	
	if (isBalanced(root)) {
		std::cout << "Tree is balanced\n";
	} else {

		std::cout << "Tree is not balanced\n";
	}

	freeBST(root);

	root = minimalTree(std::vector<int>{0,1,2,3,4,5,6,7,8,9,10,11}, 0, 11);
	inorder(root);
	std::cout << std::endl;

	if (isBalanced(root)) {
		std::cout << "Tree is balanced\n";
	} else {

		std::cout << "Tree is not balanced\n";
	}

	freeBST(root);
	return 0;
}
