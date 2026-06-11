#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	auto f = [](long long x) { return x * (x + 1) / 2; };
	long long n;
	std::cin >> n;
	long long ans = 0;
	while(f(ans) < n) ans++;
	std::cout << ans << '\n';
}