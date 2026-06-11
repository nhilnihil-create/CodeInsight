#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main() {
	int H, W; std::cin >> H >> W;
	std::vector<std::vector<char>> A(H, std::vector<char>(W));
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			std::cin >> A[i][j];

	for (int i = 0; i < W + 2; ++i)
		std::cout << '#';
	std::cout << std::endl;

	for (int i = 0; i < H; ++i) {
		std::cout << '#';
		for (int j = 0; j < W; ++j) {
			std::cout << A[i][j];
		}
		std::cout << '#' << std::endl;
	}

	for (int i = 0; i < W + 2; ++i)
		std::cout << '#';
	std::cout << std::endl;

	return 0;
}