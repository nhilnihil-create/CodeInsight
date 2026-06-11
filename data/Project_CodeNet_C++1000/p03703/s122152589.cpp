#include <bits/stdc++.h>

typedef long long LL;

const int N = 200005;
LL a[N], v[N], ans; int bit[N], n, k;
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i], a[i] += a[i - 1] - k;
	for (int i = 0; i <= n; ++i) v[i] = a[i];
	std::sort(v, v + n + 1);
	for (int i = 0; i <= n; ++i) a[i] = std::lower_bound(v, v + n + 1, a[i]) - v + 1;
	for (int i = 0; i <= n; ++i) {
		for (int j = a[i]; j; j &= j - 1) ans += bit[j];
		for (int j = a[i]; j <= n + 1; j += j & -j) ++bit[j];
	}
	std::cout << ans << '\n';
	return 0;
}