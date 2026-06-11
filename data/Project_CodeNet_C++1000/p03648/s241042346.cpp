#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long go(std::vector<long long> a) {
	int n = (int) a.size();
	long long ans = 0;
	while(1) {
		long long got = 0;
		for(auto &x : a) {
			got += x / n;
			x = (x % n) - x / n;
		}
		ans += got;
		if(got == 0) break;
		for(auto &x : a) {
			x += got;
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long k;
	std::cin >> k;
	int n = 50;
	std::vector<long long> ans(n, (k / n) + (n - 1));
	for(int i = 0; i < (int) (k % n); i++) {
		ans[i] += n;
		for(int j = 0; j < n; j++) {
			if(i != j) ans[j] = std::max(0LL, ans[j] - 1);
		}
	}
	std::cout << n << '\n';
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
	//std::cout << "got " << go(ans) << " should be " << k << '\n';
}