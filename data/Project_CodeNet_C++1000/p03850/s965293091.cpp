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
#include <random>
#include <fstream>
#include <cfloat>


int main() {
	int n; std::cin >> n;
	std::vector<int> terms(1, 0); std::cin >> terms[0];
	std::vector<std::string> ops;
	long long int result{ terms[0] };
	for (auto i = 1; i < n; i++) {
		std::string op; int value; std::cin >> op >> value;
		ops.push_back(op);
		terms.push_back(value);
		if (op == "+") {
			result += value;
		}
		else {
			result -= value;
		}
	}
	std::vector<long long int> sum_back(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		sum_back[n - i] = terms[n - i] + sum_back[n - i + 1];
	}
	int prev_minus = std::distance(ops.begin(), std::find(ops.begin(), ops.end(), "-"));
	if (prev_minus == ops.size()) {
		std::cout << sum_back.front() << '\n';
		return 0;
	}
	long long int prev_sum = std::accumulate(terms.begin(), std::next(terms.begin(), prev_minus + 1), 0LL, [](const long long int acc, const int t) {return acc + t; });
	while (prev_minus < ops.size()) {
		const int next_minus = std::distance(ops.begin(), std::find(std::next(ops.begin(), prev_minus + 1), ops.end(), "-"));
		if (next_minus < ops.size()) {
			const auto sum = std::accumulate(std::next(terms.begin(), prev_minus + 1), std::next(terms.begin(), next_minus + 1), 0LL, [](const long long int acc, const int t) {return acc + t; });
			const auto all_sum = prev_sum - sum + sum_back[next_minus + 1];
			result = std::max(result, all_sum);
			prev_sum += sum - (terms[prev_minus + 1] << 1);
		}
		prev_minus = next_minus;
	}
	std::cout << result << std::endl;
}
