#include <iostream>
#include <vector>
void zero_col(std::vector<std::vector<int>>& matrix, int c) {
	const int n = matrix.size();

	for (int i = 0; i < n; ++i) {
		matrix[i][c] = 0;
	}
}

void zero_row(std::vector<std::vector<int>>& matrix, int r) {
	const int m = matrix[0].size();

	for (int i = 0; i < m; ++i) {
		matrix[r][i] = 0;
	}
}

void zero_matrix(std::vector<std::vector<int>>& matrix) {
	std::vector<bool> rows(matrix.size(), false);
	std::vector<bool> cols(matrix[0].size(), false);

	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			if (rows[i] || cols[i]) continue;

			if (matrix[i][j] == 0) {
				rows[i] = true;
				cols[j] = true;
			}
		}
	}

	for (int i = 0; i < rows.size(); ++i) {
		if (rows[i]) zero_row(matrix, i);
	}

	for (int i = 0; i < cols.size(); ++i) {
		if (cols[i]) zero_col(matrix, i);
	}
}

int main() {
	std::vector<std::vector<int>> mat = {
		{1,2,3},
		{4,0,6},
		{7,8,9},

	};

	std::cout << "Before\n";
	for (const auto& row : mat) {
		for (const int i : row) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	zero_matrix(mat);

	std::cout << "After\n";
	for (const auto& row : mat) {
		for (const int i : row) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
