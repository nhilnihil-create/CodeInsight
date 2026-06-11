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


long long int calculate_sum(const std::vector<int>& digits, int pattern) {
	long long int sum{ 0 };
	long long int acc{ 0 };
	for (auto i = 0; i < digits.size(); ++i) {
		if ((pattern & 1) == 1) {
			sum += acc * 10 + digits[i];
			acc = 0;
		}
		else {
			acc *= 10;
			acc += digits[i];
		}
		pattern >>= 1;
	}
	return sum + acc;
}

int main() {
	std::string str; std::cin >> str;
	std::vector<int> digits;
	for (const auto c : str) digits.push_back(c - '0');
	long long int sum{ 0 };
	for (auto i = 0; i < (1 << (str.size() - 1)); ++i) {
		sum += calculate_sum(digits, i);
	}
	std::cout << sum << '\n';
}