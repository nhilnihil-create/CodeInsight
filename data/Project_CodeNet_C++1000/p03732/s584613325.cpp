#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <climits>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>
#include <iostream>
#include <deque>
#include <array>
#include <set>
#include <functional>
#include <memory>
#include <stack>
#include <numeric>
#include <climits>
#include <cfloat>
#include <bitset>

int main() {
	int n, max_weight; std::cin >> n >> max_weight;
	std::vector<std::vector<long long int>> memo(n + 1, std::vector<long long int>(3 * n + 1, LLONG_MIN));
	int w, v; std::cin >> w >> v;
	const long long initial = w;
	memo[0][0] = 0;
	memo[1][0] = v;
	for (auto i = 2; i <= n; ++i) {
		std::cin >> w >> v;
		w -= initial;
		for (auto j = i; j > 0; --j) {
			for (auto wi = 0; wi + w < memo[j].size(); ++wi) {
				if (memo[j - 1][wi] != LLONG_MIN && memo[j][wi + w] < memo[j - 1][wi] + v) {
					memo[j][wi + w] = memo[j - 1][wi] + v;
				}
			}
		}
	}
	long long int max = 0;
	for (auto i = 0; i < memo.size(); ++i) {
		for (auto j = 0; j < std::min(max_weight + 1 - initial * i, static_cast<long long int>(memo[i].size())); ++j) {
			if (max < memo[i][j]) max = memo[i][j];
		}
	}
	std::cout << max << std::endl;

}