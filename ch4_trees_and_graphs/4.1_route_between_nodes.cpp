#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>

#include "TreeAndGraph.hpp"

typedef std::vector<std::vector<int>> Graph;

bool dfs(Graph& g, int src, int dest) {
	std::stack<int> stk;
	std::unordered_set<int> set;

	stk.push(src);

	while (!stk.empty()) {
		int curr = stk.top();
		stk.pop();

		if (curr == dest) return true;

		set.insert(curr);

		for (const int neighbor : g[curr]) {
			if (set.find(neighbor) == set.end())
				stk.push(neighbor);
		}
	}

	return false;
}

bool bfs(Graph& g, int src, int dest) {
	std::queue<int> q;
	std::unordered_set<int> set;

	q.push(src);

	while (!q.empty()) {
		int sz = q.size();

		for (int i = 0; i < sz; ++i) {
			int curr = q.front();
			q.pop();

			if (curr == dest) return true;

			set.insert(curr);

			for (const int neighbor : g[curr]) {
				if (set.find(neighbor) == set.end())
					q.push(neighbor);
			}
		}
	}

	return false;
}

int main() {
	Graph g;

	while (g.empty() || g[0].empty()) {
		g = makeGraph(15);
	}

	int src = 0, dest = 12;
	
	if (bfs(g, src, dest)) {
		std::cout << "Can travel from " << src << " to " << dest << " using BFS\n";
	} else {
		std::cout << "Cannot travel from " << src << " to " << dest << " using BFS\n";
	}

	if (dfs(g, src, dest)) {
		std::cout << "Can travel from " << src << " to " << dest << " using DFS\n";
	} else {
		std::cout << "Cannot travel from " << src << " to " << dest << " using DFS\n";
	}

	printGraph(g);

	return 0;
}
