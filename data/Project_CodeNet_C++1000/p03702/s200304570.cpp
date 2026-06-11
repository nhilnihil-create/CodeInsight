#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cfloat>
#include <climits>
#include <cassert>
#include <random>

int main() {
	int n; long long int a, b; std::cin >> n >> a >> b;
	std::vector<int> monsters(n); for (auto& m : monsters) std::cin >> m;
	std::sort(monsters.begin(), monsters.end());
	int min = 1, max = 1000000000;
	while (min < max) {
		const auto mid = (min + max) >> 1;
		const auto can_defeat = std::distance(monsters.begin(), std::upper_bound(monsters.begin(), monsters.end(), mid * b));
		long long int count = 0;
		for (auto i = can_defeat; i < n; ++i) {
			count += (monsters[i] - mid * b + (a - b) - 1) / (a - b);
		}
		if (count > mid) {
			min = mid + 1;
		}
		else {
			max = mid;
		}
	}
	std::cout << min << std::endl;
}
