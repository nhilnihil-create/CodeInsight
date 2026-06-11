#include<cstdio>
#include<cstring>
#include<algorithm>
#define SQRN 4000000
#define Mod 1000000007ll
typedef long long ll;
ll jc[SQRN+50],inv[SQRN+50],f[2050][2050];
int n,k;
inline ll qpow(ll b,ll p){
	ll res=1ll;
	while(p){
		if(p&1) (res*=b)%=Mod;
		p>>=1ll;
		(b*=b)%=Mod;
	}return res;
}
inline ll C(ll x,ll y){
	return jc[x]*inv[y]%Mod*inv[x-y]%Mod;
}
int main(){
	scanf("%d%d",&n,&k);
	if(k==1)
		return puts("1"),0;
	jc[0]=1ll;
	for(ll i=1;i<=SQRN;++i)
		jc[i]=jc[i-1]*i%Mod;
	inv[SQRN]=qpow(jc[SQRN],Mod-2ll);
	for(ll i=SQRN;i>=1;--i)
		inv[i-1]=inv[i]*i%Mod;
//	printf("** %lld\n",inv[10]);
	for(int i=1;i<=n;++i)
		f[i][0]=1ll;
	for(int i=1;i<=n;++i){
//		printf("** %d: ",i);
		for(int j=1;j<=i;++j){
			(f[i][j]=f[i-1][j]+f[i][j-1]*1ll*(n-j+1)%Mod*C(n-i+(n-j+1)*(k-1)-1,k-2)%Mod)%=Mod;
//			printf("|* %lld %lld %lld *|",f[i-1][j],f[i][j-1]*(n-j+1),C(n-1+(n-j+1)*(k-1),k-2));
		}
//		puts("");
	}
	printf("%lld\n",f[n][n]);
	return 0;
}
