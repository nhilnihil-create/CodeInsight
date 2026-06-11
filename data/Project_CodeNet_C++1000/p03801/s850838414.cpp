#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;
int n, A[MAXN], rk[MAXN]; LL ansl[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i], rk[i] = i;
	std::sort(rk + 1, rk + 1 + n, [] (int a, int b) {
		return A[a] == A[b] ? a < b : A[a] > A[b];
	});
	int cur = 1, mx = n + 1;
	while (cur <= n) {
		int tv = A[rk[cur]];
		while (cur <= n && A[rk[cur]] == tv)
			mx = std::min(mx, rk[cur++]);
		ansl[mx] += (LL) (tv - A[rk[cur]]) * (cur - 1);
	}
	for (int i = 1; i <= n; ++i) std::cout << ansl[i] << '\n';
	return 0;
}
