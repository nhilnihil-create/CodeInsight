#include <iostream>

using namespace std;
long long dp[2000010] = {},sum[2000010] = {},mod = 1000000007;
int main(){
	long long i,n;
	cin >> n;
	for(i=2*n;i>=n+1;i--){
		dp[i] = 1;
		sum[i] = sum[i+1] + dp[i];
	}
	dp[n] = n; sum[n] = sum[n+1] + dp[n];
	for(i=n-1;i>=1;i--){
		(dp[i] += (sum[i+1] - sum[i+n+2]) - dp[i+2] + (n-1)*(n-1) + mod) %= mod;
		sum[i] = (sum[i+1] + dp[i])%mod;
	}
	cout << dp[1] << endl;
}