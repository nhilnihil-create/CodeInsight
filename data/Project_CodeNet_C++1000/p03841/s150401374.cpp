#include <bits/stdc++.h>

const int N = 505;
int n, x[N], ans[N * N], rk[N];

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> x[i], rk[i] = i, ans[x[i]] = i;
	std::sort(rk + 1, rk + n + 1, [] (int a, int b) {return x[a] < x[b];});
	int k = 1;
	for (int i = 1; i <= n; ++i) {
		for (int t = 1; t < rk[i]; ++t) {
			while (k <= x[rk[i]] && ans[k]) ++k;
			if (k > x[rk[i]]) return std::cout << "No\n", 0;
			ans[k] = rk[i];
		}
	}
	k = n * n;
	for (int i = n; i >= 1; --i) {
		for (int t = rk[i]; t < n; ++t) {
			while (k >= x[rk[i]] && ans[k]) --k;
			if (k < x[rk[i]]) return std::cout << "No\n", 0;
			ans[k] = rk[i];
		}
	}
	std::cout << "Yes\n"; 
	for (int i = 1; i <= n * n; ++i)
		std::cout << ans[i] << ' ';
	std::cout << '\n';
	return 0;
}