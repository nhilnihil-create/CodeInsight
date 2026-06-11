#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll ksm(ll a,ll b)
{
	ll mul=1;
	while(b)
	{
		if(b%2==1)mul=(mul*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return mul;
}
ll n,m,f[5005][5005];
string s;
int main()
{
	cin>>n;
	cin>>s;
	m=s.size();
	f[0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			f[i+1][j+1]+=2*f[i][j];
			f[i+1][j+1]%=mod;
			f[i+1][max(j-1,0)]+=f[i][j];
			f[i+1][max(j-1,0)]%=mod;
		}
	}
	ll ans=ksm(ksm(2,m),mod-2)*f[n][m]%mod;
	cout<<ans;
	return 0;
}
	