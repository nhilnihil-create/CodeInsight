# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
     
const int maxn(1e5 + 5);
     
int n, m, b[maxn], nxt[maxn], que[maxn], len, vis[maxn];
ll k, f[maxn], g[maxn];
     
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%lld", &f[i]), b[i] = i;
	for (i = n; i; --i) f[i] -= f[i - 1];
	scanf("%d%lld", &m, &k);
	for (i = 1; i <= m; ++i) scanf("%d", &j), swap(b[j], b[j + 1]);
	for (i = 1; i <= n; ++i)
		if (!vis[i]) {
			vis[i] = 1, j = b[i], que[len = 1] = i;
			while (!vis[j]) que[++len] = j, vis[j] = 1, j = b[j];
			for (j = 1; j <= len; ++j) nxt[que[j]] = que[(k + j - 1) % len + 1];
		}
	for (i = 1; i <= n; ++i) g[i] = f[nxt[i]];
	for (i = 1; i <= n; ++i) g[i] += g[i - 1], printf("%lld\n", g[i]);
	return 0;
}