#include <iostream>
#include <algorithm>

long long getLength(long long a, long long b) {
	if (a == 0 || b == 0) {
		return 0;
	}
	if (a == b) {
		return a;
	}
	long long u = a < b ? a : b;
	long long v = a > b ? a : b;
	if (v % u == 0) {
		return (v / u) * u * 2 - u;
	}
	return (v / u) * u * 2 + getLength(u, v % u);
}

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	long long n, x;
	std::cin >> n >> x;
	long long res = n;
	res += getLength(x, n - x);
	std::cout << res << '\n';
	return 0;
}