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
	std::vector<intt> s(N);
	intt total = 0;
	for (auto& r : s) {
		std::cin >> r;
		total += r;
	}
	if (total % 10 != 0) {
		std::cout << total << std::endl;
		return 0;
	}
	else {
		std::sort(s.begin(), s.end());
		bool flag = false;
		int total2;
		for (int i = 0; i < N; ++i) {
			total2 = total - s[i];
			if (total2 % 10 != 0) {
				flag = true;
				break;
			}
		}
		if (flag == true) {
			std::cout << total2 << std::endl;
		}
		else
			std::cout << 0 << std::endl;
	}
}