#include <bits/stdc++.h>

typedef long long LL;
const int N = 200005;

int n, m, a[N];
LL d1[N], d2[N], sum, ans = 1e18;

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	a[0] %= m;
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[i - 1]) a[i] += m;
		int t = (a[i] - a[i - 1]) % m;
		if (!t) continue; sum += t;
		d1[a[i] + 1] += t - 1;
		--d2[a[i - 1] + 2], ++d2[a[i] + 1];
		a[i] %= m;
	}
	for (int i = 1; i < m * 2; ++i)
		d2[i] += d2[i - 1];
	for (int i = 0; i < m * 2; ++i)
		d1[i] += d2[i];
	for (int i = 1; i < m * 2; ++i)
		d1[i] += d1[i - 1];
	for (int i = 0; i < m; ++i)
		ans = std::min(ans, sum + d1[i] + d1[i + m]);
	std::cout << ans << '\n';
	return 0;
}