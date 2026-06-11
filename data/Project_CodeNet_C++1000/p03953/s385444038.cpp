// Rabbit Exercise
// * frank_c1
// * 2017 / 11/ 07

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = (int)(1e5) + 5;
int p[maxn], pt[maxn], tmp[maxn];
LL c[maxn], nc[maxn];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%lld", &c[i]);
	for (int i = n; i >= 1; --i) c[i] -= c[i - 1], p[i] = i;
	int m; LL K; scanf("%d%lld", &m, &K);
	for (int i = 1; i <= m; ++i) {
		int x; scanf("%d", &x); swap(p[x], p[x + 1]);
	}
	for (int i = 1; i <= n; ++i) pt[i] = i;
	for (; K; K >>= 1) {
		if (K & 1) {
			memcpy(tmp, pt, sizeof(pt));
			for (int i = 1; i <= n; ++i) pt[i] = tmp[p[i]];
		}
		memcpy(tmp, p, sizeof(p));
		for (int i = 1; i <= n; ++i) p[i] = tmp[tmp[i]];
	} LL ret = 0;
	for (int i = 1; i <= n; ++i) nc[i] = c[pt[i]];
	for (int i = 1; i <= n; ++i) printf("%lld\n", (nc[i] += nc[i - 1]));
	return 0;
}