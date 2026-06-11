#include<bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

int dp[5005][5005];
signed main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int l = s.length();
	dp[0][0] = 1;
	for(int j = 1; j <= n; j++){
		dp[0][j] = (dp[0][j] + dp[1][j - 1] * 2 + dp[0][j - 1]) % mod;
		for(int i = 1; i <= n; i++){
			dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + dp[i + 1][j - 1] * 2) % mod;
		}
	}
	cout << dp[l][n];
}