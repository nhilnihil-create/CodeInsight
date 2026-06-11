/* This code is written by Nemlit */
#include<bits/stdc++.h>
using namespace std;
#define il inline
#define re register
#define rep(i, a, b) for(re int i = (a); i <= (b); ++ i)
#define drep(i, a, b) for(re int i = (b); i >= (a); -- i)
il int read() {
    re int x = 0, f = 1; re char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
    return x * f;
}
#define maxn 5005
int n, m, ans, dp[maxn][maxn], a[maxn], d[maxn];
long long sum;
il void solve(int l, int r, int *Dp) {
	if(l == r) {
		rep(i, 0, m) dp[l][i] = Dp[i];
		return;
	}
	int DP[m + 5], mid = (l + r) >> 1;
	memcpy(DP, Dp, sizeof(DP));
	rep(i, l, mid) drep(j, a[i], m) DP[j] |= DP[j - a[i]];
	rep(i, mid + 1, r) drep(j, a[i], m) Dp[j] |= Dp[j - a[i]];
	solve(l, mid, Dp), solve(mid + 1, r, DP);
}
signed main() {
	n = read(), m = read(), d[0] = 1;
	rep(i, 1, n) a[i] = read(), sum += a[i], ans += a[i] >= m;
	solve(1, n, d);
	if(sum >= m) rep(i, 1, n) if(a[i] < m) rep(j, m - a[i], m - 1) if(dp[i][j]) { ++ ans; break; }
	printf("%lld", n - ans);
	return 0;
}
