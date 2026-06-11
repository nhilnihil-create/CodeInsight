#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int N=5005;
int dp[N][N];
int Pow(int x,int k)
{
	int s=1;
	while(k)
	{
		if(k&1)
			s=(s*x)%mod;
		x=(x*x)%mod;
		k>>=1;
	}
	return s;
}
main()
{
	memset(dp,0,sizeof(dp));
	int n,m;
	string s;
	dp[0][0]=1;
	for(int i=0;i<=5000;i++)
	{
		for(int j=0;j<=5000;j++)
		{
			if(dp[i][j]==0) 
				continue;
			dp[i+1][j+1]=(dp[i+1][j+1]+(2*dp[i][j])%mod)%mod;
			(dp[i+1][max(0LL,j-1)]+=dp[i][j]%mod)%=mod;	
		}
	}
	cin>>n>>s;
	cout<<(dp[n][s.size()]*Pow(Pow(2,s.size()),mod-2))%mod<<endl;
	return 0;
}
