#include <iostream>
#include <numeric>

int main() {
	long long n, x;
	std::cin >> n >> x;
	std::cout << 3LL * (n - std::gcd(n, x)) << '\n';
	return 0;
}