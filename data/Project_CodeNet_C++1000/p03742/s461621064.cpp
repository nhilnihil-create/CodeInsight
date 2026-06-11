#include <bits/stdc++.h>

using ll = long long;
constexpr ll inf = static_cast<ll>(1e17);
constexpr ll mod = static_cast<ll>(1e9 + 7);

ll x, y;
int main() {
	std::cin >> x >> y;

	if (std::abs(x - y) <= 1)
		std::cout << "Brown" << std::endl;
	else
		std::cout << "Alice" << std::endl;

	return 0;
}
