#include <vector>
#include <iostream>
#include <cassert>

void rotate_matrix(std::vector<std::vector<int>>& matrix) {
	const int n = matrix.size();
	const int layer_count = n / 2;

	assert(n == matrix[0].size());

	for (int i = 0; i < layer_count; ++i) {
		for (int  j = i; j < n - i - 1; ++j) {
			const int offset = j - i;
			const int top = matrix[i][j];
			const int right = matrix[j][n-i-1];
			const int bottom = matrix[n-i-1][n-i-1-offset];
			const int left = matrix[n-i-1-offset][i];

			matrix[i][j] = left;
			matrix[j][n-i-1] = top;
			matrix[n-i-1][n-i-1-offset] = right;
			matrix[n-i-1][i] = bottom;
		}
	}

}

int main() {
	std::vector<std::vector<int>> mat = {
		{0,1,2},
		{3,4,5},
		{6,7,8}
	};
	std::cout << "Before:\n";
	for (const std::vector<int>& row : mat) {
		for (const int i : row) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	rotate_matrix(mat);

	std::cout << "After:\n";
	for (const std::vector<int>& row : mat) {
		for (const int i : row) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}


	return 0;
}
