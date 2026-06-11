#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)

typedef long long LL;
const int MOD=1e9+7;
const int N=200005;

LL fac[N],inv[N];

LL C(int n,int m) {
	return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}

int main(void) {
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	rep(i,2,N-1) {
		fac[i]=fac[i-1]*i%MOD;
		inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
	}
	rep(i,2,N-1) inv[i]=inv[i-1]*inv[i]%MOD;
	int n,m,a,b; scanf("%d%d%d%d",&n,&m,&a,&b);
	LL ans=0;
	rep(i,1,n-a) {
		ans=(ans+C(b+i-2,i-1)*C(n+m-i-b-1,n-i)%MOD)%MOD;
	}
	printf("%lld\n", ans);
	return 0;
}