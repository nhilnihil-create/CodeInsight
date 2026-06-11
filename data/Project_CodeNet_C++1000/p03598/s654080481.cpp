#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int N, K; std::cin >> N >> K;
	std::vector<int> X(N);
	int count = 0;
	for (auto& r : X) {
		std::cin >> r;
		if (r > std::abs(K - r))
			count += std::abs(K - r) * 2;
		else
			count += r * 2;
	}
	std::cout << count << std::endl;

	return 0;
}