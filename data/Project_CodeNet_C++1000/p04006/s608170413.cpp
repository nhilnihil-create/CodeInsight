#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 2e3 + 5;

int n, x, a[N], f[N][N];
LL ans = 1e18;

LL calc(int c) {
	LL r = 0;
	for(int i = 1; i <= n; ++i) {
		int mi;
		if(i - c > 0) {
			mi = f[i - c][i];
		} else {
			mi = min(f[1][i], f[n - (c + 1 - i) + 1][n]);
		}
		r += mi;
	}
	return r;
}
int main() {
	scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for(int i = 1; i <= n; ++i) {
		f[i][i] = a[i];
		for(int j = i + 1; j <= n; ++j)
			f[i][j] = min(f[i][j - 1], a[j]);
	}
	for(int i = 0; i <= n; ++i)
		ans = min(ans, (LL) i * x + calc(i));
	printf("%lld\n", ans);
	return 0;
}	
