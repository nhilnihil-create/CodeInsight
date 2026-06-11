#include <iostream>
#include <vector>

int main() {
	std::size_t n;
	long long k;
	std::cin >> n >> k;
	std::vector<long long> a(n), b(n);
	for (std::size_t i = 0; i < n; i++) {
		std::cin >> a[i] >> b[i];
	}

	auto solve = [&] (long long x) -> long long {
		long long value = 0;
		for (std::size_t i = 0; i < n; i++) {
			if ((x | a[i]) == x) value += b[i];
		}
		return value;
	};

	long long ans = solve(k);
	for (long long s = 1; s <= (k << 1); s <<= 1) {
		long long x = (s - 1);
		for (long long p = (1LL << 35); p > 0; p >>= 1) {
			if ((x | p) <= k) x |= p;
		}
		if (x <= k) ans = std::max(ans, solve(x));
	}

	std::cout << ans << '\n';
	
	return 0;
}