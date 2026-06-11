#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN=2005,MAXL=MAXN*MAXN*2-3,mod=1e9+7;
int N,K;
ll fac[MAXN*MAXN*4],inv[MAXN*MAXN*4];
ll C(ll n,ll m) {
//	printf("C(%lld,%lld)\n",n,m);
	if(n<0||m<0||n<m) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll f[MAXN][MAXN];
int main() {
	scanf("%d%d",&N,&K);
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=MAXL;++i) fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<=MAXL;++i) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=MAXL;++i) inv[i]=inv[i]*inv[i-1]%mod;
	//printf("%lld\n",C(5,3));
	if(K<2) {
		cout<<1<<endl;
		exit(0);
	}
	f[0][0]=1;
	for(int i=1;i<=N;++i) {
		for(int j=0;j<=i;++j) {
			if(i==j) {
				f[i][j]=f[i][j-1]*C( N*K-i-(j-1)*(K-1)-1 ,K-2)%mod;
			} else {
				f[i][j]=(f[i-1][j]+f[i][j-1]*C( N*K-i-(j-1)*(K-1)-1 ,K-2)%mod)%mod;
			}
			//printf("f[%d][%d]=%lld\n",i,j,f[i][j]);
		}
	}
	printf("%lld\n",f[N][N]*fac[N]%mod);
	return 0;
}