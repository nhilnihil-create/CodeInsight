#include <bits/stdc++.h>
using namespace std;

const long long inf = 1000000000000000037;
const int maxn = 1003;
const int maxm = 2003;

int n, m;
int a[maxm], b[maxm], c[maxm];
long long d[maxn], d_old[maxn];

signed main () {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) 
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	for (int i = 1; i <= n; ++i)
		d[i] = -inf;
	d[1] = 0;
	for (int j = 0; j < n - 1; ++j) {
		for (int i = 1; i <= m; ++i) {
			if (d[a[i]] != -inf)
				d[b[i]] = max(d[b[i]], d[a[i]] + c[i]);
		}
	}
	memcpy(d_old, d, sizeof(d));
	for (int j = 0; j < n - 1; ++j) {
		for (int i = 1; i <= m; ++i) {
			if (d[a[i]] != -inf)
				d[b[i]] = max(d[b[i]], d[a[i]] + c[i]);
		}
	}
	if (d_old[n] == d[n])
		cout << d[n] << '\n';
	else
		cout << "inf\n";
}
