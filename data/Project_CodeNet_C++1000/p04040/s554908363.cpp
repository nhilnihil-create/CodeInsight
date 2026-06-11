#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,MOD=1e9+7;
int n,m,A,B,ans;
int bin[N],inv[N];

inline int pow(int a,int n)
{
	int res=1;
	while (n)
	{
		if (n&1ll) res=res*a%MOD;
		a=a*a%MOD;
		n>>=1ll;
	}
	return res;
}

inline int C(int a,int b)
{
	return bin[a]*inv[a-b]%MOD*inv[b]%MOD;
}

inline int solve(int sx,int sy,int tx,int ty)
{
	return C(tx-sx+ty-sy,tx-sx);
}

signed main(){
	bin[0]=inv[0]=1;
	for (register int i=1; i<=2e5; ++i) bin[i]=bin[i-1]*i%MOD; 
	for (register int i=1; i<=2e5; ++i) inv[i]=pow(bin[i],MOD-2ll);
	scanf("%lld%lld%lld%lld",&n,&m,&A,&B);
	for (register int i=1; i<=n-A; ++i) ans=(ans+solve(1,1,i,B)*solve(i,B+1,n,m)%MOD)%MOD; 
	printf("%lld\n",ans);
return 0;
}