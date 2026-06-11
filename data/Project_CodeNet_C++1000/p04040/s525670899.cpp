#include<bits/stdc++.h>
using namespace std;
#define RI register int
const int mod=1e9+7,N=100005;
int n,m,A,B,ans;
int fac[N<<1],ni[N<<1];
int qm(int x) {return x>=mod?x-mod:x;}
int ksm(int x,int y) {
	int re=1;
	for(;y;y>>=1,x=1LL*x*x%mod) if(y&1) re=1LL*re*x%mod;
	return re;
}
int C(int d,int u) {return 1LL*fac[d]*ni[u]%mod*ni[d-u]%mod;}
int main()
{
	scanf("%d%d%d%d",&n,&m,&A,&B);
	fac[0]=1;for(RI i=1;i<=n+m;++i) fac[i]=1LL*fac[i-1]*i%mod;
	ni[n+m]=ksm(fac[n+m],mod-2);
	for(RI i=n+m-1;i>=0;--i) ni[i]=1LL*ni[i+1]*(i+1)%mod;
	ans=C(n+m-2,n-1);
	for(RI i=1;i<=B;++i) {
		int kl=C(n-A+i-1,i-1);
		if(i>1) kl=qm(kl-C(n-A+i-2,i-2)+mod);
		ans=qm(ans-1LL*kl*C(A+m-i-1,A-1)%mod+mod);
	}
	printf("%d\n",ans);
	return 0;
}