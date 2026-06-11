#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int main()
{
	
	int n,m;
	cin>>n>>m;
	ll fact[100005];
	fact[0]=1,fact[1]=1;
	for(int i=1;i<=100004;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
	}
	if((m>=n-1&&m<=n+1)||(n>=m-1&&n<=m+1))
	{
		ll res;
		if(n>m)
		{
			res=((fact[n]*fact[m])%mod)%mod;
		}
		else if(m>n)
		{
			res=((fact[m]*fact[n])%mod);
		}
		else 
		{
			res=2*(fact[m]*fact[n])%mod;
		}
		cout<<res;
	}
	else cout<<0;
}
	