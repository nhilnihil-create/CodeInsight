#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=8000005;
ll n,k,fac[N],inv[N],f[2005][2005],mod=1e9+7;
ll power(ll a,ll b){
	ll res=1,tmp=a;
	while(b){
		if(b&1)res=res*tmp%mod;
		tmp=tmp*tmp%mod;
		b>>=1;
	}
	return res;
}
ll C(ll n,ll m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
} 
int main(){
	scanf("%lld%lld",&n,&k);
	if(k==1){
		puts("1");
		return 0;
	}
	fac[0]=inv[0]=1;
	for(int i=1;i<=n*k;i++){
		fac[i]=fac[i-1]*i%mod;
		inv[i]=power(fac[i],mod-2);
	}
	for(int i=0;i<=n;i++)f[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
			f[i][j]=f[i-1][j]%mod+f[i][j-1]%mod*(n-j+1)%mod*C(n*k-i-1-(j-1)*(k-1),k-2)%mod;
	printf("%lld",f[n][n]%mod);
	return 0;
}