#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 2000 + 10, inf = 1e18;
ll dp[N][N], a[N];

int main() {
	ll n, x;
  	cin >> n >> x;
  	for (int i = 0; i < n; i++)
    	cin >> a[i];
	for (int i = 0; i < n; i++)
    	dp[0][i] = a[i];
    for (int i = 1; i < n; i++)
		for (int j = 0; j < n; j++)
  			dp[i][j] = min(dp[i - 1][j], a[(i + j) % n]);
	ll ans = inf;
  	for (int i = 0; i < n; i++) {
    	ll cnt = x * i;
    	for (int j = 0; j < n; j++)
			cnt += dp[i][j];
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}