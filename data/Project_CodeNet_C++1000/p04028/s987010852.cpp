#include<bits/stdc++.h>
using namespace std;

const int maxn=5005, mod=1e9+7;

int N,L;
int dp[maxn][maxn];
char s[maxn];

main()
{
	scanf("%d%s",&N,s); L=strlen(s);
	
	memset(dp,0,sizeof(dp));
	
	dp[0][0]=1;
	for (int i=1; i<=N; ++i)
	{
		dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
		
		for (int j=1; j<=i; ++j)
	        dp[i][j] = (dp[i-1][j-1] * 2ll + dp[i-1][j+1]) % mod;
	}
	
	long long res=dp[N][L];
	for (int i=1; i<=L; ++i)
		// res /= 2
		res = res * 500000004 % mod;
		//500000004 = 0.5 mod 1e9+7
	cout<<res;
}