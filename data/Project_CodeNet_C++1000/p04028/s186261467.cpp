#include <iostream>
#include <string>
#define int long long
#define MOD 1000000007
using namespace std;

signed main(){
	int n,dp[5001][5001] = {};
	string s;
	cin >> n >> s;
	dp[0][s.length()] = 1;
	for(int i = 0;i < n;i++){
		for(int j = 0;j <= n;j++){
			if(j + 1 <= n) dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * 2) % MOD;
			dp[i + 1][max(0ll,j - 1)] = (dp[i + 1][max(0ll,j - 1)] + dp[i][j]) % MOD;
		}
	}
	cout << dp[n][0] << endl;
	return 0;
}