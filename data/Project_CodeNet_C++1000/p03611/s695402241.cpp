#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

int main() {
	intt X; std::cin >> X;
	std::vector<intt> a(X);
	std::map<intt, intt> MAP;
	for (auto& r : a) {
		std::cin >> r;
		++MAP[r];
		++MAP[r - 1];
		++MAP[r + 1];
	}
	intt max = 0;
	for (auto& r : MAP) {
		max = std::max(max, r.second);
	}
	std::cout << max << std::endl;


	return 0;
}