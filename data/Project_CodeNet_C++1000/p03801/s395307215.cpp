#include <bits/stdc++.h>

typedef long long ll;
const int N = 100054;

int n;
int a[N], o[N];
ll ans[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

int main() {
	int i, j, k;
	scanf("%d", &n), o[n] = k = n;
	for (i = 0; i < n; ++i) scanf("%d", a + i), o[i] = i;
	std::stable_sort(o, o + n, [] (const int x, const int y) {return a[x] > a[y];});
	for (j = i = 0; i < n; i = j) {
		for (; j < n && a[o[i]] == a[o[j]]; ++j);
		down(k, o[i]), ans[k] += ll(a[o[i]] - a[o[j]]) * j;
	}
	for (i = 0; i < n; ++i) printf("%lld\n", ans[i]);
	return 0;
}