#include<bits/stdc++.h>
using namespace std;
#define nn 2002
#define mod 1000000007
#define ll long long

ll f[nn*nn],rf[nn*nn];
ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1) res=res*x%mod;
		x=x*x%mod;y=y/2;
	}
	return res;
}
ll c(ll x,ll y)
{
	if(x>y)  return 0;
	return f[y]*rf[x]%mod*rf[y-x]%mod;
}

ll dp[nn][nn];ll n,k;
int main()
{
	f[0]=1;for(int i=1;i<nn*nn;i++) f[i]=f[i-1]*i%mod;
	rf[nn*nn-1]=qpow(f[nn*nn-1],mod-2);
	for(int i=nn*nn-2;i>=0;i--) rf[i]=rf[i+1]*(i+1)%mod;

	cin>>n>>k;k--;
	if(k==0)
	{
		cout<<1;
		exit(0);
	}
	dp[0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			dp[i+1][j]+=dp[i][j];
			dp[i+1][j]%=mod;
			dp[i][j+1]+=dp[i][j]*c(k-1,n*k+n-k*j-i-1);
			dp[i][j+1]%=mod;
		}
	}
	
	cout<<dp[n][n]*f[n]%mod;
	return 0;
} 