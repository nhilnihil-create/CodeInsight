#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
#define N 2010

int n,m;
ll dp[N][N],fac[N*N],inv[N*N];

ll power(ll x,ll y) {
	ll ret=1;
	for (;y;y>>=1,x=x*x%mod)
		if (y&1) ret=ret*x%mod;
	return ret;
}

ll C(ll x,ll y) {
	if (y>x) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}

int main()
{
	scanf("%d%d",&n,&m);
	if (m==1) return puts("1"),0;
	fac[0]=1; for (int i=1;i<=n*m;i++) fac[i]=fac[i-1]*i%mod;
	inv[n*m]=power(fac[n*m],mod-2);
	for (int i=n*m-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	dp[0][1]=1;
	for (int i=2;i<=n;i++) dp[0][i]=dp[0][i-1]*C(i*(m-1)-1,m-2)%mod;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			dp[i][j]=(dp[i-1][j]+dp[i][j-1]*C(j*(m-1)+i-1,m-2)%mod)%mod;
	printf("%lld\n",dp[n][n]*fac[n]%mod);
	return 0;
}