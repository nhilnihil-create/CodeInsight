#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr int iinf = static_cast<int>(1e9);
constexpr ll mod = static_cast<ll>(1e9 + 7);
constexpr long long MOD(long long in) {
	return in % mod;
}

int n;
ll a[100005];
int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}

	if (sum % (((ll)n) * (n + 1) / 2) != 0) {
		std::cout << "NO" << std::endl;
		return 0;
	}

	ll cnt = 0;
	ll k = sum / (((ll)n) * (n + 1) / 2);
	for (int i = 0; i < n; i++) {
		auto val = a[(i + 1) % n] - a[i] - k;

		if (val > 0 || (-val) % n != 0) {
			std::cout << "NO" << std::endl;
			return 0;
		}
		cnt += (-val) / n;
	}

	if (cnt == k)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;

	return 0;
}
