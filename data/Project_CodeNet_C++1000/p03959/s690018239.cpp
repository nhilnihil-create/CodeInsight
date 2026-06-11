#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr ll mod = static_cast<ll>(1e9 + 7);

int n;
ll t[100005], a[100005];
ll mn[100005], mx[100005];
int main() {
	std::cin >> n;

	for (int i = 0; i < n; ++i)
		std::cin >> t[i];
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	for (int i = 0; i < n; ++i) {
		if (i == 0 || t[i] > t[i - 1]) {
			mn[i] = t[i];
			mx[i] = t[i];
		}
		else {
			mn[i] = 1LL;
			mx[i] = t[i];
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		if (i == n - 1 || a[i] > a[i + 1]) {
			mn[i] = std::max(mn[i], a[i]);
			mx[i] = std::min(mx[i], a[i]);
		}
		else {
			mn[i] = std::max(mn[i], 1LL);
			mx[i] = std::min(mx[i], a[i]);
		}
	}

	ll ans = 1LL;
	for (int i = 0; i < n; ++i) {
		if (mn[i] > mx[i]) {
			std::cout << 0 << std::endl;
			return 0;
		}
		else {
			ans *= (mx[i] - mn[i] + 1);
			ans %= mod;
		}
	}

	std::cout << ans << std::endl;
	return 0;
}
