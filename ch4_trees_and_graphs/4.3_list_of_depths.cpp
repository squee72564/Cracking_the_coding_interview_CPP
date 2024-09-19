#include <utility>
#include <iostream>
#include <vector>
#include <queue>

#include "TreeAndGraph.hpp"

static TreeNode * minimalTree(const std::vector<int>& v, int l, int r) {
	if (l > r) return nullptr;

	const int mid = l + (r-l) / 2;

	return new TreeNode(v[mid], minimalTree(v, l, mid-1), minimalTree(v, mid+1, r));
}

struct Node {
	TreeNode* data;
	Node *next;

	Node() = default;
	Node(TreeNode* t) : data(t), next(nullptr) {};
	~Node() = default;
};

std::vector<Node*> list_of_depths(TreeNode *root) {
	std::queue<TreeNode*> q;
	std::vector<Node*> ret;

	q.push(root);

	while (!q.empty()) {
		int sz = q.size();

		Node *ll_root = nullptr;
		Node *ll_curr = nullptr;

		for (int i = 0; i < sz; ++i) {
			TreeNode *curr = q.front();
			q.pop();
			Node *new_node = new Node(curr);

			if (!ll_root) {
				ll_curr = new_node;
				ll_root = new_node;
			} else {
				ll_curr->next = new_node;
				ll_curr = ll_curr->next;
			}

			if (curr->left)  q.push(curr->left);
			if (curr->right) q.push(curr->right);
		}

		ret.push_back(ll_root);
	}

	return ret;
}

int main() {
	TreeNode *root = minimalTree(std::vector<int>{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14}, 0, 14);

	std::cout << "Tree:\n";

	inorder(root);
	std::cout << std::endl;
	
	std::vector<Node*> lists = list_of_depths(root);

	std::cout << "List of linked-lists\n";
	for (const Node *root : lists) {
		while (root) {
			std::cout << root->data->val << ", ";
			root = root->next;
		}
		std::cout << std::endl;
	}

	return 0;
}

