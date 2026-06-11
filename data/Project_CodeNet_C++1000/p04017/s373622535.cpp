#include <bits/stdc++.h>

const int N = 100005;

int n, l, q, x[N], p[N][17];

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> x[i];
	std::cin >> l >> q;
	for (int i = 0, j = 0; i < n; p[i++][0] = j)
		while (j + 1 < n && x[j + 1] - x[i] <= l) ++j;
	for (int i = 1; i < 17; ++i)
		for (int j = 0; j < n; ++j)
			p[j][i] = p[p[j][i - 1]][i - 1];
	while (q--) {
		int l, r, ans = 1; std::cin >> l >> r, --l, --r; if (l > r) std::swap(l, r);
		for (int i = 16; ~i; --i) if (p[l][i] < r) ans += 1 << i, l = p[l][i];
		std::cout << ans << '\n';
	}
	return 0;
}