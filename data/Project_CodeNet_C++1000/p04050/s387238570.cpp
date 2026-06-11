#include <bits/stdc++.h>

const int N = 105;
int n, m, a[N];
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= m; ++i) std::cin >> a[i];
	std::sort(a + 1, a + m + 1, [] (int x, int y) { return (x & 1) > (y & 1); });
	if (a[3] & 1) return std::cout << "Impossible" << '\n', 0;
	if (m > 1) std::swap(a[2], a[m]);
	for (int i = 1; i <= m; ++i) std::cout << a[i] << " \n"[i == m];
	std::cout << m - (a[1] == 1) + (m == 1) << '\n';
	if (a[1] > 1) std::cout << a[1] - 1 << ' ';
	for (int i = 2; i <= m; ++i)
		std::cout << a[i] + (i == m) << ' ';
	if (m == 1) std::cout << 1 << ' ';
	return 0;
}