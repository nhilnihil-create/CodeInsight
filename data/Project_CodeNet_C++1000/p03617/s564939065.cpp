#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main() {
	long long Q, H, S, D, N; std::cin >> Q >> H >> S >> D >> N;
	long long small = std::min({ Q * 4, H * 2, S});
	std::cout << std::min((N * small), ((small * (N % 2)) + (D * (N / 2)))) << std::endl;

	return 0;
}
