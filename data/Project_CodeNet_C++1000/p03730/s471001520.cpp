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
	intt A, B, C; std::cin >> A >> B >> C;
	for (intt i = 1; i < 1000000; ++i) {
		intt a = A * i;;
		if (a % B == C) {
			std::cout << "YES" << std::endl;
			return 0;
		}
	}
	std::cout << "NO" << std::endl;

	return 0;
}