#include <bits/stdc++.h>

const int MAXN = 200010;
typedef long long LL;
LL A[MAXN], li[MAXN];
int n, K;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	LL ans = 0;
	for (int i = 1; i <= n; ++i)
		std::cin >> A[i], A[i] -= K, A[i] += A[i - 1], ans += A[i] >= 0;
	memcpy(li, A, n + 1 << 3);
	std::sort(li + 1, li + 1 + n);
	for (int i = 0; i <= n; ++i)
		A[i] = std::lower_bound(li + 1, li + 1 + n, A[i]) - li;
	memset(li, 0, sizeof li);
	for (int i = 1; i <= n; ++i) {
		for (int x = A[i]; x; x &= x - 1) ans += li[x];
		for (int x = A[i]; x <= n; x += x & -x) ++li[x];
	}
	std::cout << ans << std::endl;
	return 0;
}
