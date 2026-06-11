#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,m;
ll F[4000005],inv[4000005],f[2005][2005];
ll quick_pow(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1) ans=ans*a%mod;
	return ans;
}
ll C(ll n,ll m){
	return F[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	scanf("%d%d",&n,&m);
	if(m==1) return puts("1"),0;
	F[0]=inv[0]=1;
	for(int i=1;i<=n*m;i++) F[i]=F[i-1]*i%mod,inv[i]=quick_pow(F[i],mod-2);
	f[0][0]=1; 
	int len=n*m;
	for(int i=0;i<=n;i++){
		for(int p=0;p<=i;p++){
			if(!i&&!p) continue;
			if(i) f[i][p]=f[i-1][p];
			if(p) f[i][p]=(f[i][p]+f[i][p-1]*C(len-(p-1)*(m-1)-i-1,m-2))%mod;
		}
	}
	printf("%lld",f[n][n]*F[n]%mod);
	return 0;
}