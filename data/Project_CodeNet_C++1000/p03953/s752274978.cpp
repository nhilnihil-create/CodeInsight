#include <bits/stdc++.h>

typedef long long ll;

const int kN = 1e5 + 5;

int n, m, a[kN], t[kN]; ll x[kN], d[kN], ans[kN], bas[kN];

void QPow(ll k) {
	while(k) {
		if(k & 1) {
			for(int i = 1; i <= n; ++i) t[i] = ans[bas[i]];
			for(int i = 1; i <= n; ++i) ans[i] = t[i];
		}
		for(int i = 1; i <= n; ++i) t[i] = bas[bas[i]];
		for(int i = 1; i <= n; ++i) bas[i] = t[i];
		k >>= 1;
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", x + i), ans[i] = i, bas[i] = i;
	ll k;
	scanf("%d%lld", &m, &k);
	for(int i = 1; i <= m; ++i) scanf("%d", a + i), std::swap(bas[a[i]], bas[a[i] + 1]);
	for(int i = 1; i <= n; ++i) d[i] = x[i] - x[i - 1];
	QPow(k);
	for(int i = 1; i <= n; ++i) t[i] = d[ans[i]];
	ll cur_ans = 0;
	for(int i = 1; i <= n; ++i) {
		cur_ans += t[i];
		printf("%lld.0\n", cur_ans);
	}
	return 0;
}