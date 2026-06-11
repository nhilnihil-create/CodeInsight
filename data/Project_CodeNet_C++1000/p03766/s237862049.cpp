#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7, i2 = (mod+1)/2;
ll dp[maxn], p[maxn], fp[maxn];
void add(ll &a, ll b) {
	a += b;
	if(a >= mod) a -= mod;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = n-1;
	for(int i = 2; i <= n; i++) dp[i] = n*1ll*(n-1)%mod;
	fp[0] = 0;
	p[0] = 0;
	for(int i = 1; i <= n; i++) {
		p[i] = p[i-1];
		fp[i] = fp[i-1];
		if(i > 2)
			add(dp[i], mod - (mod + fp[i-3] - p[i-3]*i%mod + p[i-3] + p[i-3])%mod);
		add(fp[i], dp[i]*i%mod);
		add(p[i], dp[i]);
	}
	cout << (p[n]+1)%mod;
	return 0;
}
