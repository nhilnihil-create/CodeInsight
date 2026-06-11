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
	intt N; std::cin >> N;
	std::vector<intt> a(N);
	for (auto& r : a) std::cin >> r;
	intt count = 0;
	intt t = 1;
	while (true) {
		if (t == 2) {
			std::cout << count << std::endl;
			return 0;
		}
		t = a[t - 1];
		++count;
		if (count >= N + 1)
			break;
	}
	std::cout << -1 << std::endl;
}
