#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100005;
int n, m, p[N][62]; ll k, a[N], d[N], tmp[N];

int main () {
	cin >> n;
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for (int i = 1; i < n; ++i) d[i] = a[i + 1] - a[i];
	cin >> m >> k;
	for (int i = 1; i < n; ++i) p[i][0] = i;
	for (int i = 1, x; i <= m; ++i) {
		scanf("%d", &x);
		swap(p[x][0], p[x - 1][0]);
	}
	for (int l = 1; l <= 60; ++l)
		for (int i = 1; i <= n; ++i) p[i][l] = p[p[i][l - 1]][l - 1];
	for (int l = 60; ~l; --l) if (k >> l & 1) {
		for (int i = 1; i <= n; ++i) tmp[i] = d[i];
		for (int i = 1; i <= n; ++i) d[i] = tmp[p[i][l]];
	}
	for (int i = 2; i < n; ++i) a[i] = a[i - 1] + d[i - 1];
	for (int i = 1; i <= n; ++i) printf("%lld.0\n", a[i]);
	return 0;
}