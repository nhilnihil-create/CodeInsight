#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[52][52][2510];

signed main(){
	int n, A; scanf("%d%d", &n, &A);
	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	dp[0][0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= n; j++){
			for(int k = 0; k <= 2500; k++){
				dp[i + 1][j][k] += dp[i][j][k];
				if(j >= 1 && k - a[i] >= 0) dp[i + 1][j][k] += dp[i][j - 1][k - a[i]];
			}
		}
	}
	ll ans = 0;
	for(int j = 1; j <= n; j++){
		ans += dp[n][j][j * A];
	}
	cout << ans << endl;
}