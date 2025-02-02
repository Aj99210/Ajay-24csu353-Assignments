#include <iostream>
#include <vector>

void printMatrix(std::vector<std::vector<int>> matrix) {
	for (int row = 0; row < matrix.size(); row++) {
		for (int column = 0; column < matrix.size(); column++) {
			std::cout << matrix[row][column] << '\t';
		}
		std::cout << '\n';
	}
}

void funnyRotate(std::vector<std::vector<int>>& matrix) {
	int n = matrix.size();

	for (int row = 0; row < n; row++) {
		for (int column = row; column < n; column++) {
			std::swap(matrix[row][column], matrix[column][row]);
		}
	}

	for (int row = 0; row < n; row++) {
		for (int column = 0; column < n / 2; column++) {
			int temp = matrix[row][column];
			matrix[row][column] = matrix[row][n - 1 - column];
			matrix[row][n - 1 - column] = temp;
		}
	}
}

int main() {
	int n;
	std::cout << "Enter the size of square matrix: ";
	std::cin >> n;

	std::vector<std::vector<int>> matrix(n, std::vector<int>(n));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << "Enter element for Row " << i + 1 << " Column " << j + 1 << " : ";
			std::cin >> matrix[i][j];
		}
	}

	std::cout << "\nOriginal Matrix: \n";
	printMatrix(matrix);

	funnyRotate(matrix);

	std::cout << "\nRoated Matrix: \n";
	printMatrix(matrix);

	return 0;
}