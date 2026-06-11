#include<bits/stdc++.h>
using namespace std;
#define RI register int
const int mod=1000000007,N=2005,M=4000005;
int n,K,f[N][N],fac[M],ni[M];
int qm(int x) {return x>=mod?x-mod:x;}
int ksm(int x,int y) {
	int re=1;
	for(;y;y>>=1,x=1LL*x*x%mod) if(y&1) re=1LL*re*x%mod;
	return re;
}
void prework() {
	fac[0]=1;for(RI i=1;i<=n*K;++i) fac[i]=1LL*fac[i-1]*i%mod;
	ni[n*K]=ksm(fac[n*K],mod-2);
	for(RI i=n*K-1;i>=0;--i) ni[i]=1LL*ni[i+1]*(i+1)%mod;
}
int C(int d,int u) {return 1LL*fac[d]*ni[u]%mod*ni[d-u]%mod;}
int main()
{
	scanf("%d%d",&n,&K);
	if(K==1) {puts("1");return 0;}
	prework();--K;
	f[0][0]=1;
	for(RI i=1;i<=n;++i) {
		for(RI j=0;j<=i;++j) {
			if(j) f[i][j]=f[i][j-1];
			f[i][j]=qm(f[i][j]+1LL*f[i-1][j]*C(i*K+j-1,K-1)%mod);
		}
	}
	printf("%lld\n",1LL*f[n][n]*fac[n]%mod);
    return 0;
}