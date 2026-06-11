#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 1200000

const LL mod=1000000007;
LL n,f[N],g[N],sum,ans;

void upd(LL &x,LL y){x=(x+y)%mod;}

int main(){
	scanf("%lld",&n);
	upd(ans,(n-1)*n+1);
	f[0]=g[0]=1;
	for (LL i=1;i<=n;++i){
		if (i>=3) upd(sum,g[i-3]);
		f[i]=sum+1;
		g[i]=(g[i-1]+f[i])%mod;
		if (i<n) upd(ans,f[i]*(n-1));
		if (i<n-1) upd(ans,f[i]*(n-1)%mod*(n-1));
	}
	printf("%lld\n",ans);
	
	return 0;
}
			