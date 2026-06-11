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

int main() {
	int n; std::cin >> n;
	std::vector<int> hotels(n); for (auto& h : hotels) std::cin >> h;
	int l; std::cin >> l;
	std::vector<std::vector<int>> step{ std::vector<int>(n, n) };
	for (auto i = 0; i < n; ++i) {
		step[0][i] = std::distance(hotels.begin(), std::upper_bound(hotels.begin(), hotels.end(), hotels[i] + l)) - 1;
	}
	while (1 << step.size() <= n) {
		std::vector<int> next(n);
		for (auto i = 0; i < n; ++i) {
			next[i] = step.back()[step.back()[i]];
		}
		step.emplace_back(std::move(next));
	}
	int q; std::cin >> q;
	for (auto i = 0; i < q; ++i) {
		int a, b; std::cin >> a >> b; --a; --b;
		if (a > b) std::swap(a, b);
		int day{ 1 };
		for (int i = step.size() - 1; i >= 0; --i) {
			if (step[i][a] < b) {
				day += 1 << i;
				a = step[i][a];
			}
		}
		std::cout << day << '\n';
	}
}
