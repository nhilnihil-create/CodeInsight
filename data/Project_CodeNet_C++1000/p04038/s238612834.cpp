#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
int const M=2000+10,mod=1e9+7,inf=1e9+10;
int dp[M][M],rev[M*M],fact[M*M];
int pw(int x,int y)
{
	if(y==0)return 1;
	int tmp=pw(x,y/2);
	if(y%2==0)return (tmp*tmp)%mod;
	return ((tmp*tmp)%mod*x)%mod;
}
int C(int n,int r)
{
	int tmp=fact[r]*fact[n-r];
	tmp%=mod;
	tmp=pw(tmp,mod-2);
	tmp*=fact[n];
	tmp%=mod;
	return tmp;
}
int32_t main()
{	
	int n,k;
	cin>>n>>k;
	fact[0]=1;
	for(int i=1;i<=4e6;i++)fact[i]=fact[i-1]*i,fact[i]%=mod,rev[i]=pw(fact[i],mod-2);
	if(k==1)return cout<<1,0;
	for(int i=n+1;i>=1;i--)
	{
		for(int j=i;j>=1;j--)
		{
			if(i==n+1 && j==n+1)
			{
				dp[i][j]=1;
				continue;
			}
			dp[i][j]+=dp[i+1][j];
			dp[i][j]%=mod;
			if(n*k-(i-1)-((j-1)*(k-1))-1>=0)
				dp[i][j]+=C(n*k-(i-1)-((j-1)*(k-1))-1,k-2)*dp[i][j+1];
			dp[i][j]%=mod;
			//cout<<c[n*k-(i-1)-((j-1)*(k-1))][k-1]<<" "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	cout<<(dp[1][1]*fact[n])%mod;
}	