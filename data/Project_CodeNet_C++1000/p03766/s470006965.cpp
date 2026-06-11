#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
long long f[N]={0},s[N]={0},ans=0LL,n;;
int main()
{
	scanf("%lld",&n);
	f[0]=1ll;s[0]=1ll;
	f[1]=1ll;s[1]=2;
	f[2]=1ll;s[2]=3;
	for(int i=3;i<=n;i++)
	{
		f[i]=(f[i-1]+s[i-3])%mod;
		s[i]=(s[i-1]+f[i])%mod;
	}
	for(int i=0;i<=n-2;i++) 
	  ans+=f[i]*((n-1)*(n-1)%mod+i+1)%mod;
	ans=(ans+(n-1)*f[n-1]%mod)%mod;
	ans=(ans+f[n])%mod;
	printf("%lld\n",ans);
	return 0;
}