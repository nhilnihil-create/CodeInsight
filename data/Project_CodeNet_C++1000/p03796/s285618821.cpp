#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main() {
	long long N; std::cin >> N;
	long long power = 1;
	for (int i = 1; i <= N; ++i) {
		power *= i;
		power %= 1000000007;
	}
	std::cout << power << std::endl;
	return 0;
}
