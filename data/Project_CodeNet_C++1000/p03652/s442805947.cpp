#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n, std::vector<int>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> a[i][j];
			a[i][j]--;
		}
	}
	std::vector<bool> present(m, true);
	auto getBest = [&]() {
		std::vector<int> freq(m, 0);
		for(int i = 0; i < n; i++) {
			for(auto j : a[i]) {
				if(present[j]) {
					freq[j]++;
					break;
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < m; i++) {
			if(freq[i] > freq[ans]) ans = i;
		}
		return std::pair<int, int>(ans, freq[ans]);
	};
	int ans = n;
	for(int i = 0; i < m; i++) {
		auto curPair = getBest();
		ans = std::min(ans, curPair.second);
		present[curPair.first] = false;
	}
	std::cout << ans << '\n';
}