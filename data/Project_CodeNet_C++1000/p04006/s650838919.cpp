#include <bits/stdc++.h>

typedef long long ll;

const int kN = 2e3 + 5;

ll a[kN], c[kN];

int main() {
	int n; ll ans = 0, x;
	scanf("%d%lld", &n, &x);
	for(int i = 1; i <= n; ++i) scanf("%lld", a + i), c[i] = a[i], ans += a[i];
	for(int i = 1; i <= n; ++i) {
		ll cur_cost = x * i;
		for(int j = 1; j <= n; ++j) {
			c[j] = std::min(c[j], a[(j + i - 1) % n + 1]);
			cur_cost += c[j];
		}
		ans = std::min(cur_cost, ans);
	}
	printf("%lld", ans);
	return 0;
}