#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN=2005,MOD=1e9+7;
int n,k,fac[MAXN*MAXN],inv[MAXN*MAXN],dp[MAXN];

ll quick_pow(ll a,ll b)
{
	ll ret=1;
	for(;b;b>>=1,a=a*a%MOD)
		if(b&1) ret=ret*a%MOD;
	return ret;
}
ll C(int a,int b)
{if(a<b) return 0;return 1ll*fac[a]*inv[a-b]%MOD*inv[b]%MOD;}
void inc(int &a,int b){a+b>MOD?a+=b-MOD:a+=b;}

int main()
{
	scanf("%d%d",&n,&k);
	if(k==1) return puts("1"),0;
	fac[0]=dp[0]=1;
	for(int i=1;i<=n*k;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	inv[n*k]=quick_pow(fac[n*k],MOD-2);
	for(int i=n*k-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%MOD;
	
	for(int i=0;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			inc(dp[j],dp[j-1]*C(i+(k-1)*j-1,k-2)%MOD);
	
	ll res=1ll*dp[n]*fac[n]%MOD;
	printf("%lld",res);
	return 0;
}