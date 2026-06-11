#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int n, x[N], f[N], m, g[N], ans[N];
long long k;

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &x[i]), f[i] = ans[i] = i;
	scanf("%d%lld", &m, &k);
	for (int i = 1, a; i <= m; ++i) scanf("%d", &a), swap(f[a], f[a - 1]);
	for (; k; k >>= 1) {
		if (k & 1) {
			for (int i = 1; i < n; ++i) g[i] = ans[f[i]];
			for (int i = 1; i < n; ++i) ans[i] = g[i];
		}
		for (int i = 1; i < n; ++i) g[i] = f[f[i]];
		for (int i = 1; i < n; ++i) f[i] = g[i];
	}
	long long s = x[1];
	for (int i = 1; i <= n; ++i) {
		printf("%lld\n", s);
		s += x[ans[i] + 1] - x[ans[i]];
	}
	return  0;
}