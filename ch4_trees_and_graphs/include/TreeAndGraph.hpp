#ifndef TAG_HPP
#define TAG_HPP

#include <iostream>
#include <cassert>
#include <vector>
#include <random>
#include <algorithm>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode *l) : val(v), left(l), right(nullptr) {}
	TreeNode(int v, TreeNode *l, TreeNode *r) : val(v), left(l), right(r) {}
};

void postorder(TreeNode *root) {
	if (!root) return;

	postorder(root->left);
	postorder(root->right);
	std::cout << root->val << ", ";
}

void preorder(TreeNode *root) {
	if (!root) return;

	std::cout << root->val << ", ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(TreeNode *root) {
	if (!root) return;

	inorder(root->left);
	std::cout << root->val << ", ";
	inorder(root->right);
}


TreeNode * insertIntoBST(TreeNode *root, int i) {
	if (!root) {
		root = new TreeNode(i);
	} else if (i <= root->val) {
		root->left = insertIntoBST(root->left, i);
	} else {
		root->right = insertIntoBST(root->right, i);
	}

	return root;
}

TreeNode * createBST(std::vector<int>&& v) {
	assert(v.size() > 0);

	TreeNode *root = new TreeNode(v[0]); 

	for (int i = 1; i < v.size(); ++i) {
		insertIntoBST(root, v[i]);
	}

	return root;
}

void freeBST(TreeNode *root) {
	if (!root) return;

	freeBST(root->left);
	freeBST(root->right);

	delete root;
}

std::vector<std::vector<int>> makeGraph(int n) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> neighbor_dis(0, n-1);
	std::uniform_int_distribution<> dis(0, n/4);
	std::vector<bool> mapCheck(n, false);
	std::vector<std::vector<int>> mp;

	while (!std::all_of(mapCheck.cbegin(), mapCheck.cend(), [](const bool b){ return b; })) {
		mp = std::vector<std::vector<int>>(n);
		mapCheck = std::vector<bool>(n, false);

		for (int i = 0; i < n; ++i) {
			std::vector<bool> nodeCheck(n, false);
			for (int j = 0; j < dis(gen); ++j) {
				int neighbor = neighbor_dis(gen);
				if (!nodeCheck[neighbor]) {
					nodeCheck[neighbor] = true;
					mapCheck[neighbor] = true;
					mp[i].push_back(neighbor);
				}
			}
		}
	}

	return mp;
}

void printGraph(std::vector<std::vector<int>>& g) {
	for (int i = 0; i < g.size(); ++i) {
		std::cout << i << ": ";
		for (int j = 0; j < g[i].size(); ++j) {
			std::cout << g[i][j] << ", ";
		}
		std::cout << std::endl;
	}
}

#endif
