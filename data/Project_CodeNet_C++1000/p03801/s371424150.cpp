#include <bits/stdc++.h>

typedef long long LL;
const int N = 100005;

int n, a[N], rk[N], pos;
LL ans[N];

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n, pos = n;
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	for (int i = 0; i <= n; ++i) rk[i] = i;
	std::sort(rk, rk + n + 1, [] (int x, int y) {return a[x] > a[y];});
	for (int l = 0, r = 0; l < n; l = r) {
		while (a[rk[l]] == a[rk[r]]) pos = std::min(pos, rk[r++]);
		ans[pos] += (LL) (a[rk[l]] - a[rk[r]]) * r;
	}
	for (int i = 0; i < n; ++i) std::cout << ans[i] << '\n';
	return 0;
}