// Infinite Sequence
// * frank_c1
// * 2017 / 09 / 30

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = (int)(1e6) + 5;
const int mo = (int)(1e9) + 7;
int f[maxn];

inline void add(int& x, int v) {
	x += v; if (x >= mo) x -= mo;
}

int main() {
	int n, res = 0;
	scanf("%d", &n);
	f[0] = 1; int w = 1;
	for (int i = 1; i <= n; ++i) {
		f[i] = w; if (i > 1) add(f[i], mo - f[i - 2]); add(w, f[i]);
	} LL ww = (1LL * (n - 1) * (n - 1)) % mo;
	for (int i = 0; i + 1 < n; ++i) add(res, f[i] * (ww + i + 1) % mo); 
	add(res, 1LL * f[n - 1] * (n - 1) % mo); add(res, f[n]);
	return printf("%d\n", res), 0;
}