#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr int iinf = static_cast<int>(1e9);
constexpr ll mod = static_cast<ll>(1e9 + 7);
constexpr long long MOD(long long in) {
	return in % mod;
}

ll n, x;
int main()
{
	std::cin >> n >> x;

	ll ans = n;
	ll a = std::max(x, n - x), b = std::min(x, n - x);
	while (b != 0) {
		ans += a / b * b * 2;
		auto aa = b, bb = a % b;
		a = aa, b = bb;
	}

	std::cout << ans - a << std::endl;
	return 0;
}
