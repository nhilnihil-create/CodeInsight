#include<cstdio>
#include<algorithm>
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
using namespace std;

const int N=2010,mod=1e9+7;
int n,m,K,fac[N*N],inv[N*N],f[N][N];

int ksm(int a,int b){
	int res=1;
	for (; b; a=1ll*a*a%mod,b>>=1)
		if (b & 1) res=1ll*res*a%mod;
	return res;
}

int C(int n,int m){ return n<m ? 0 : 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod; }

int main(){
	scanf("%d%d",&n,&K); m=n*K;
	if (K==1){ puts("1"); return 0; }
	fac[0]=1; rep(i,1,m) fac[i]=1ll*fac[i-1]*i%mod;
	inv[m]=ksm(fac[m],mod-2);
	for (int i=m; i; i--) inv[i-1]=1ll*inv[i]*i%mod;
	f[0][0]=1;
	rep(i,1,n) rep(j,0,i)
		f[i][j]=(f[i][j]+f[i-1][j]+(!j?0:1ll*f[i][j-1]*(n-j+1)%mod*C((n-i)+(n-j+1)*(K-1)-1,K-2)%mod))%mod;
	printf("%d\n",f[n][n]);
	return 0;
}