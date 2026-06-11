#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=2007;
const ll mod=1e9+7;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
ll f[N][N],fac[N*N],inv[N*N],s[N];
ll n,k;
ll C(ll x,ll y){return fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	scanf("%lld%lld",&n,&k);
	if(k==1){
		puts("1");
		return 0;
	}
	fac[0]=1;
	rep(i,n*k)fac[i]=fac[i-1]*i%mod;
	inv[n*k]=Pow(fac[n*k],mod-2);
	for(ll i=n*k;i;i--)inv[i-1]=inv[i]*i%mod;
	f[0][0]=1;
	rep0(i,n){
		for(ll j=i;~j;j--)s[j]=(s[j+1]+f[i][j])%mod;
		rep0(j,i+1)f[i+1][j+1]=s[j]*C(i*k-j+k-2,k-2)%mod;
	}
	for(ll j=n;~j;j--)s[j]=(s[j+1]+f[n][j])%mod;
	printf("%lld\n",s[0]*fac[n]%mod);
	return 0;
}
