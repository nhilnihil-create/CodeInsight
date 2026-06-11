#include <bits/stdc++.h>

const int N = 100005;

int n, a[N];
bool in(int x, int y) { return x <= n && a[x] >= y; }

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	std::sort(a + 1, a + n + 1, [] (int x, int y) { return x > y; });
	int p = 0, L = 0, R = 0; while (in(p + 1, p + 1)) ++p;
	for (int i = p + 1; i <= n; ++i) R ^= a[i] >= p;
	L = a[p] - p & 1;
	std::cout << (L || R ? "First" : "Second" ) << '\n';
	return 0;
}