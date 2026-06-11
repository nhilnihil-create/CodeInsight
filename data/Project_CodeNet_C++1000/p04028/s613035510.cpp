#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <climits>
#include <numeric>
#include <queue>
#include <cmath>
#include <iomanip>
#include <array>
#include <string>
#include <stack>
#include <cassert>
#include <memory>

constexpr int mod = 1000000007;
long long int power(const long long int base, const int exp) {
	switch (exp) {
	case 0: return 1LL;
	case 1: return base % mod;
	default: return power(base * base % mod, exp >> 1) * power(base, exp & 1) % mod;
	}
}
int main() {
	int n; std::cin >> n;
	std::string str; std::cin >> str;
	std::vector<std::vector<long long int>> memo(n + 1, std::vector<long long int>(n + 1, 0));
	memo[0][0] = 1;
	for (auto i = 1; i < memo.size(); ++i) {
		memo[i][0] = (memo[i - 1][0] + memo[i - 1][1]) % mod;
		for (auto j = 1; j < n; ++j) {
			memo[i][j] = ((memo[i - 1][j - 1] << 1) + memo[i - 1][j + 1]) % mod;
		}
		memo[i][n] = (memo[i - 1][n - 1] << 1) % mod;
	}
	std::cout << memo[n][str.size()] * power((mod + 1) >> 1, str.size()) % mod << '\n';
}
