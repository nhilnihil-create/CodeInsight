#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5 * 1e3 + 10;
const int MOD = 1e9 + 7;
int n, k;
int dp[N][N];
string s;
int powe(int x, int y){
	if(!y) return 1ll;
	int mid = powe(x, y/2);
	if(y % 2) return mid * mid % MOD * x % MOD;
	else return mid * mid % MOD;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	k = s.length();
	dp[0][0] = 1; 
	for(int i = 1; i <= n; ++i)	for(int j = 0; j <= n; ++j){
		dp[i][j] = dp[i - 1][j + 1];
		if(j > 0) dp[i][j] = (dp[i][j] + 2*dp[i - 1][j - 1]) % MOD;
		else dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
	}
	int ans = dp[n][k];
	ans = ans * powe(powe(2, k), MOD - 2) % MOD;
	cout << ans;
}