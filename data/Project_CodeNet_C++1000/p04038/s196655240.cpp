#include <cstdio>

typedef long long ll;
const int maxn=2000+10,mod=1000000007;
ll fac[maxn*maxn],ifac[maxn*maxn],f[maxn][maxn];

ll power(ll a,ll b){
	ll ret=1;
	while(b){
		if(b&1)ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}

ll C(ll n,ll m){
	if(n<m)return 0;
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

int main(){
	// freopen("in.txt","r",stdin);
	int n,m;scanf("%d%d",&n,&m);
	if(m==1){printf("%d\n",1);return 0;}
	fac[0]=ifac[0]=1;
	for(int i=1;i<=n*m;++i)fac[i]=fac[i-1]*i%mod;
	ifac[n*m]=power(fac[n*m],mod-2);
	for(int i=n*m-1;i>=1;--i)ifac[i]=ifac[i+1]*(i+1)%mod;
	f[0][0]=1;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=i;++j){
			if(i>j)f[i][j]+=f[i-1][j];
			if(j)f[i][j]+=f[i][j-1]*C(n*m-i-(j-1)*(m-1)-1,m-2)%mod;
			f[i][j]%=mod;
			// printf("%d %d %lld\n",i,j,f[i][j]);
		}
	printf("%lld\n",f[n][n]*fac[n]%mod);
	return 0;
}