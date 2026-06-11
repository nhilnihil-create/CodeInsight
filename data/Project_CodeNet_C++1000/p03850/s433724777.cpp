#include <bits/stdc++.h>

long long a[100054];
int b[100054];

int main() {
	int i, n = 0, m, x; long long s = 0, ans = LLONG_MAX; char op[4];
	for (scanf("%d%lld", &m, a); --m; )
		scanf("%s%d", op, &x), *op == 43 ? a[n] += x : (++n, a[n] = b[n] = x);
	for (++n, i = 1; i <= n; ++i) ans = std::min(ans, s + a[i]), s += b[i];
	printf("%lld\n", std::accumulate(a, a + n, -2 * ans));
	return 0;
}