#include <iostream>
#include <vector>

void printSpiral(int n) {
	
	std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

	int num = 1;
	int top = 0, bottom = n - 1, left = 0, right = n - 1;

	while (num <= n * n) {

		for (int i = top; i <= right && num <= n * n; i++) {
			matrix[top][i] = num++;
		} top++;

		for (int i = top; i <= bottom && num <= n * n; i++) {
			matrix[i][right] = num++;
		} right--;

		for (int i = right; i >= left && num <= n * n; i--) {
			matrix[bottom][i] = num++;
		} bottom--;

		for (int i = bottom; i >= top && num <= n * n; i--) {
			matrix[i][left] = num++;
		} left++;

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << '\n';
	}
}

int main() {
	int n;
	std::cout << "Enter the size of Spiraly pattern :D : ";
	std::cin >> n;

	printSpiral(n);
	return 0;
}