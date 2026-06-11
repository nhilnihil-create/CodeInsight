#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long power(long long N, long long expo)
{
	long long ans = 1;
	while(expo)
	{
		if(expo % 2)
			ans = ans * N % MOD;
		N = N * N % MOD;
		expo /= 2;
	}
	return ans;
}

int main()
{
	int n,a;
	cin>>n>>a;
	int b[n];
	for(int i=0; i<n; i++)
		cin>>b[i];
	sort(b,b+n);
	long long dp[51][51][3001];
	memset(dp,0,sizeof(dp));
	dp[1][1][b[0]]=1;
	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			for(int k=0; k<3000; k++)
				dp[i][j][k]=dp[i-1][j][k];
			if(j==1) dp[i][j][b[i-1]]=1+dp[i-1][j][b[i-1]];
			else
			{
				for(int k=0; k<3000; k++)
					dp[i][j][k+b[i-1]]+=dp[i-1][j-1][k];
			}
		}
	}
	long long ans=0;
	for(int i=1; i<=n; i++)
		ans+=dp[n][i][a*i];
	cout<<ans<<endl;
	return 0;
}
