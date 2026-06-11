#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int f[2010][2010],fac[4000010],inv[4000010];
inline int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
inline int C(int n,int m) {
	if(n<m)return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	if(k==1) {
		puts("1");
		return 0;
	}
	fac[0]=1;
	for(int i=1;i<=n*k;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n*k]=qpow(fac[n*k],mod-2);
	for(int i=n*k-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	f[0][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++) {
			f[i+1][j]=(f[i+1][j]+f[i][j])%mod;
			f[i][j+1]=(f[i][j+1]+1ll*C(n*k-i-j*(k-1)-1,k-2)*f[i][j])%mod;
		}
	printf("%lld\n",1ll*f[n][n]*fac[n]%mod);
	return 0;
}