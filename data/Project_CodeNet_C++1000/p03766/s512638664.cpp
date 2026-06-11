#include<iostream>
#include<cstdio>
#define ll long long
#define up(a,b) a=(a+b)%mod
using namespace std;
const int mod=1000000007;
const int maxn=2000100;
int n;
ll f[maxn],s[maxn],ans=0;
int main()
{
	scanf("%d",&n);
	f[0]=s[0]=1;
	for(int i=1;i<=2*n;i++)
	{
		int l=max(0,i-n-1),r=min(n-1,i-3);
		if(l<=r) f[i]=(s[r]-(l==0?0:s[l-1])+mod)%mod;
		if(i<=n) up(f[i],f[i-1]);
		s[i]=(s[i-1]+f[i])%mod;
	}
	for(int i=n;i<=2*n;i++)
		up(ans,f[i]);
	for(int i=0;i<=n-2;i++)
		up(ans,f[i]*(n-1)%mod*(n-1)%mod);
	printf("%lld",ans);		
	return 0;
}