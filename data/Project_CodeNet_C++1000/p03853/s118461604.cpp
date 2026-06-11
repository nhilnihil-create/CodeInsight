#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	int H, W; std::cin >> H >> W;
	std::vector<std::vector<char>> C(H, std::vector<char>(W));
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			std::cin >> C[i][j];
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			std::cout << C[i][j];
		}
		std::cout << std::endl;
		for (int j = 0; j < W; ++j) {
			std::cout << C[i][j];
		}
		std::cout << std::endl;
	}

	return 0;
}