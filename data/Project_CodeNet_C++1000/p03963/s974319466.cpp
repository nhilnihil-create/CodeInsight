#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

int main() {
	long long N, K; std::cin >> N >> K;
	long long ans = K;
	for (int i = 0; i < N - 1; ++i) {
		ans *= K - 1;
	}
	std::cout << ans << std::endl;
}
