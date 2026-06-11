#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int N; std::cin >> N;
	int ans = 0;
	int sum = -1;
	for (int x = 1; x <= N; ++x) {
		int count = 0;
		int i = x;
		while (i % 2 == 0) {
			i = i / 2;
			++count;
		}
		if (count > sum) {
			sum = count;
			ans = x;
		}
	}
	std::cout << ans << std::endl;

	return 0;
}