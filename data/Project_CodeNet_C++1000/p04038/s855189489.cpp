#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fac[4000005],ifac[4000005],inv[4000005],p=1e9+7;
void ycl(int n){
	fac[1]=fac[0]=ifac[0]=ifac[1]=inv[0]=inv[1]=1;
	for (int i=2;i<=n;i++){
		inv[i]=(p-p/i)*inv[p%i]%p;
		fac[i]=fac[i-1]*i%p;
		ifac[i]=ifac[i-1]*inv[i]%p;
	}
}
ll C(int n,int m){
	if (n<m) return 0;
	return ((fac[n]*ifac[m])%p*ifac[n-m])%p;
}
ll f[2005][2005];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if (k<=1){printf("1\n"); return 0;}
	ycl(n*k);
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=n;j>=0;j--){
			if (j<=i) f[i][j]=(f[i][j]+f[i-1][j-1]*C(i*k-j-1,k-2))%p;
			f[i][j]=(f[i][j]+f[i][j+1])%p;
		}
	}
	ll ans=f[n][0];
	ans=ans*fac[n]%p;
	printf("%lld\n",ans);
	return 0;
}