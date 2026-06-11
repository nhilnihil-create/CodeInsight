#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll P=1e9+7,MAXN=4e6+10;
ll n,k,fac[MAXN],inv[MAXN],dp[2010][2010];
ll qpow (ll a,ll b) {
	ll res=1;
	while (b) {
		if (b&1) {
			res=(res*a)%P;
		}
		a=(a*a)%P;
		b>>=1;
	}
	return res;
}
ll c (ll n,ll m) {
	return (((fac[n]*inv[m])%P)*inv[n-m])%P;
}
int main () {
	scanf("%lld%lld",&n,&k);
	if (k==1) {
		printf("%d\n",1);
		return 0;
	}
	fac[0]=inv[0]=1;
	for (ll i=1;i<=n*k;i++) {
		fac[i]=(i*fac[i-1])%P;
	}
	inv[n*k]=qpow(fac[n*k],P-2);
	for (ll i=n*k-1;i>=1;i--) {
		inv[i]=(inv[i+1]*(i+1))%P;
	}
	for (int i=1;i<=n;i++) {
		dp[i][0]=1;
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=i;j++) {
			dp[i][j]=(dp[i-1][j]+(((dp[i][j-1]*(n-j+1))%P)*c(n*k-i-1-(j-1)*(k-1),k-2))%P)%P;
		}
	}
	printf("%lld\n",dp[n][n]);
	return 0;
}