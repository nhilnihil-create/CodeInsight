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
#include <deque>
#include <set>
#include <functional>
#include <memory>
#include <stack>
#include <numeric>
#include <cfloat>
#include <bitset>
template<typename F>
int upper_bound(int from, int until, const F& predicate) {
	while (from < until) {
		const auto mid = (from + until) / 2;
		if (predicate(mid)) until = mid;
		else from = mid + 1;
	}
	return until;
}
int main() {
	int n, k; std::cin >> n >> k;
	std::vector<int> cards(n); for (auto& c : cards) std::cin >> c;
	std::sort(cards.begin(), cards.end());
	std::vector<bool> memo(k, false);
	std::cout << upper_bound(0, n, [&memo, &cards, k, n](const int ci) {
		const auto card = cards[ci];
		if (card < k) {
			std::fill(memo.begin(), memo.end(), false); memo[0] = true;
			auto is_need = false;
			for (auto i = 0; i < n && !is_need; ++i) if (i != ci) {
				for (int j = k - cards[i] - 1; j >= 0; --j) if (memo[j]) {
					memo[j + cards[i]] = true;
					if (j + cards[i] + card >= k) {
						is_need = true;
						break;
					}
				}
			}
			return is_need;
		}
		else {
			return true;
		}
		}) << std::endl;
}