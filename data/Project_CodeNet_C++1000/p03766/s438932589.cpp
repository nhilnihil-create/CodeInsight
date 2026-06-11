#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#define inf 1e8
#define maxn int(1e6+5)
#define ll long long
#define eps 1e-8
#define mod int(1e9+7)
#define xrn_love_hcy_forever main
using namespace std;
ll f[maxn],s[maxn],ans=0;
int xrn_love_hcy_forever() {
	ll n;
	int i,j;
	scanf("%lld",&n);
//	f[1]=s[1]=n;
//	f[2]=(n*n)%mod;
//	s[2]=(s[1]+f[2]);
//	/*
	f[1]=s[0]=f[2]=f[0]=1;
	s[1]=2;
	s[2]=3;
//	*/
//	cout<<f[2]<<endl;
	for(i=3; i<=n; i++) {
		f[i]=(f[i-1]+s[i-3])%mod;
		s[i]=(s[i-1]+f[i])%mod;
	}
//	ans=ans*(n-1)%mod;
//	ans%=mod;
//	ans=ans*(n-1)%mod;
//	ans%=mod;
//	cout<<f[n]<<endl;
	ans=(ans+(n-1)%mod*f[n-1]%mod)%mod;
	ans+=f[n]%mod;
//	cout<<ans<<endl;
	for(i=0; i<=n-2; i++) ans=(ans+f[i]*((n-1)*(n-1)%mod+i+1)%mod)%mod;
	printf("%lld\n",ans%mod);
	return 0;
}