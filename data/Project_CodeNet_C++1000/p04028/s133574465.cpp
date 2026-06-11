#include <bits/stdc++.h>
long long n, k, dp[5005][5005];
std::string s;
signed main(){
	std::cin>>n>>s, dp[0][0]=1, k=s.length();
	for(int i=1; i<=n; i++)
		for(int j=0; j<=n; j++)
			if(j==0) dp[i][j]=(dp[i-1][j]+dp[i-1][j+1])%1000000007;
			else dp[i][j]=(dp[i-1][j-1]*2+dp[i-1][j+1])%1000000007;
	for(int i=1; i<=k; i++) dp[n][k]=(dp[n][k]*500000004)%1000000007;
	std::cout<<dp[n][k];
}