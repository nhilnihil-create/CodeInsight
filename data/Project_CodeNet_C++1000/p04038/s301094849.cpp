#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 2200

const LL mod=1000000007;
LL n,m,ans,f[N][N],fac[N*N],ifac[N*N];

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

LL C(LL x,LL y){
	return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

int main(){
	scanf("%lld%lld",&n,&m);
	fac[0]=1; for (LL i=1;i<=n*m;++i) fac[i]=fac[i-1]*i%mod;
	ifac[n*m]=inv(fac[n*m]); for (LL i=n*m-1;i>=0;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
	if (m==1){puts("1"); return 0;}
	f[0][0]=1;
	for (LL i=1;i<=n;++i){
		f[i][0]=1;
		for (LL j=1;j<i;++j)
			f[i][j]=(f[i][j-1]*C(n-i+(n-j+1)*(m-1)-1,m-2)+f[i-1][j])%mod;
		f[i][i]=f[i][i-1]*C(n-i+(n-i+1)*(m-1)-1,m-2)%mod;
	}
	ans=f[n][n]*fac[n]%mod;
	printf("%lld\n",ans);
	
	return 0;
}
			