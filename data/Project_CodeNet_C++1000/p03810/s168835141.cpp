#include <bits/stdc++.h>

const int N = 100005;
int n, a[N];
bool solve() {
	int odd = 0, even = 0, g = 0;
	for (int i = 1; i <= n; ++i)
		++(a[i] & 1 ? odd : even);
	if (even & 1) return 1;
	if (odd > 1) return 0;
	for (int i = 1; i <= n; ++i) if (a[i] == 1) return 0; else if (a[i] & 1) --a[i];
	for (int i = 1; i <= n; ++i) g = std::__gcd(g, a[i]);
	for (int i = 1; i <= n; ++i) a[i] /= g;
	return !solve();
}

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	std::cout << (solve() ? "First" : "Second") << '\n';
	return 0;
}