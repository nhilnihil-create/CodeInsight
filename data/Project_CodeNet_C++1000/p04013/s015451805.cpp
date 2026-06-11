#define rep(i, n) for(int i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll dp[51][51][2501];

int main() {
	int n,a;
	cin >> n >> a;
	vector<int> x(n);
	rep(i,n) cin >> x[i];
	int max_x = 0;
	rep(i,n) max_x = max(max_x, x[i]);

	rep(j,n+1) rep(k,n+1) rep(s,n*max_x+1) dp[j][k][s] = 0;
	dp[0][0][0] = 1;
	rep(j,n+1) rep(k,n+1) rep(s,n*max_x+1) {
		if (j>=1 && s<x[j-1]) dp[j][k][s] = dp[j-1][k][s];
		else if (j>=1 && k>=1 && s>=x[j-1]) dp[j][k][s] =  dp[j-1][k][s] + dp[j-1][k-1][s-x[j-1]];
	}
	ll ans = 0;
	for (int k=1;k<=n;k++) ans += dp[n][k][k*a];
	cout << ans << endl;

	return 0;
}
