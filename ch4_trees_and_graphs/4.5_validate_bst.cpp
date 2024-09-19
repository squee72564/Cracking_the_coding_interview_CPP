#include <iostream>
#include <limits.h>

#include "TreeAndGraph.hpp"

static TreeNode * minimalTree(const std::vector<int>& v, int l, int r) {
	if (l > r) return nullptr;

	const int mid = l + (r-l) / 2;

	return new TreeNode(v[mid], minimalTree(v, l, mid-1), minimalTree(v, mid+1, r));
}

void insertAlternating(TreeNode *root, bool left, int v) {
	if (!root) return;

	if (left && !root->left) {
		root->left = new TreeNode(v);
		return;
	}
	if (!left && !root->right) {
		root->right = new TreeNode(v);
		return;
	}

	if (left) insertAlternating(root->left, false, v);
	else	  insertAlternating(root->right, true, v);
}

TreeNode * createNonBST(const std::vector<int>&& v) {
	TreeNode *root = new TreeNode(v[0]);

	for (int i = 1; i < v.size(); ++i) {
		insertAlternating(root, true, v[i]);
	}

	return root;
}

bool validateBST(TreeNode* root, int &prev) {
	if (!root) return true;

	if (!validateBST(root->left, prev)) return false;
	
	if (root->val <= prev) return false;
	prev = root->val;

	return validateBST(root->right, prev);
}

int main() {
	TreeNode *root = createNonBST({0,1,2,3,4,5,6,7,8,9,10,11});
	inorder(root);
	std::cout << std::endl;

	int t = INT_MIN;

	if (validateBST(root, t)) {
		std::cout << "Tree is valid BST\n";
	} else {

		std::cout << "Tree is not valid BST\n";
	}

	freeBST(root);

	root = minimalTree(std::vector<int>{0,1,2,3,4,5,6,7,8,9,10,11}, 0, 11);
	inorder(root);
	std::cout << std::endl;

	t = INT_MIN;

	if (validateBST(root, t)) {
		std::cout << "Tree is valid BST\n";
	} else {

		std::cout << "Tree is not valid BST\n";
	}

	freeBST(root);
	
	return 0;
}
