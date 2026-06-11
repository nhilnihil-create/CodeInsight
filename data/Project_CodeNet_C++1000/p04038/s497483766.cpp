#include<bits/stdc++.h>
#define rg register
#define il inline
#define cn const
#define fp(i,a,b) for(rg int i=(a),ed=(b);i<=ed;++i)
using namespace std;
typedef cn int cint;
cint inf=0x3f3f3f3f,maxn=2010,maxm=4000010,mod=1000000007;
int n,k,f[maxn][maxn];
int fac[maxm],inv[maxm],ifac[maxm];
il int c(cint &n,cint &m){
	return 1ll*fac[n]*ifac[m]%mod *ifac[n-m]%mod;
}
int main(){
	scanf("%d %d",&n,&k);
	if(k==1){puts("1");return 0;}
	fac[0]=1; fp(i,1,n*k)fac[i]=1ll*fac[i-1]*i%mod;
	inv[1]=1; fp(i,2,n*k)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	ifac[0]=1; fp(i,1,n*k)ifac[i]=1ll*ifac[i-1]*inv[i]%mod;
	f[0][0]=1;
	fp(i,0,n)fp(j,0,n)if(i+j){
		if(i) f[i][j]=1ll*f[i-1][j]*c(i*(k-1)+j-1,k-2)%mod;
		if(j&&i>=j)f[i][j]=(f[i][j]+f[i][j-1])%mod;
	}
	printf("%d\n",1ll*f[n][n]*fac[n]%mod);
	return 0;
}