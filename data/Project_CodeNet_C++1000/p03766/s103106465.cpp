#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int main(){
	ll n;
	cin >> n;
	
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	
	static ll dp[1000010][4] = {};
	dp[1][1] = 1;
	for(int i = 1 ; i < n ; i ++){
		dp[i+1][0] = dp[i][3];
		dp[i+1][1] = dp[i][0];
		dp[i+1][2] = dp[i][1]+dp[i][2];
		if(dp[i+1][2] >= MOD)dp[i+1][2] -= MOD;
		dp[i+1][3] = dp[i][3]+dp[i+1][2];
		if(dp[i+1][3] >= MOD)dp[i+1][3] -= MOD;
	}
	
	/*for(int i = 1 ; i <= n ; i ++){
		cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
	}*/
	
	ll x = (n-1)*n; x %= MOD;
	ll ret = x+1;
	for(int i = 1 ; i <= n-2 ; i ++){
		ret += x*(dp[i][0]+dp[i][1]+dp[i][2]);
		ret %= MOD;
	}
	ret += (n-1)*(dp[n-1][0]+dp[n-1][1]+dp[n-1][2]);
	//ret += dp[n][0]+dp[n][1]+dp[n][2];
	cout << ret%MOD << endl;
}