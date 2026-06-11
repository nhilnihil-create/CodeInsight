#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int n, m, a[N], f[N], cnt[3];
bool o[N], p[N];

int find (int x) {
	if (x == f[x]) return x;
	int pos = f[x];
	f[x] = find(f[x]);
	a[x] ^= a[pos];
	return f[x];
}

int main () {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 1, u, v, ru, rv; i <= m; ++i) {
		scanf("%d%d", &ru, &rv);
		u = find(ru); v = find(rv);
		if (u == v) {
			if (a[ru] == a[rv]) o[u] |= 1;
		} else {
			a[u] = a[ru] ^ a[rv] ^ 1;
			f[u] = v;
			o[v] |= o[u];
		}
	}
	for (int i = 1; i <= n; ++i) if (i != find(i)) p[find(i)] = 1;
	for (int i = 1; i <= n; ++i) if (i == find(i)) { if (p[i]) ++cnt[!o[i]]; else ++cnt[2]; }
	printf("%lld\n", 1ll * cnt[0] * cnt[0] + 2ll * cnt[1] * cnt[1] + 2ll * cnt[1] * cnt[0] + 2ll * cnt[2] * (n - cnt[2]) + 1ll * cnt[2] * cnt[2]);
	return 0;
}