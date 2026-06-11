#include<iostream>
#include<cstdio>
const int mod=1e9+7;
const int M=2e3+10;
const int N=4e6+10;
using namespace std;
int n,k,h[N],inv[N],finv[N],f[M][M];
int C(int n,int m) {
	return 1ll*h[n]*finv[m]%mod*finv[n-m]%mod;
}
void Pre() {
	h[0]=finv[0]=inv[1]=1;
	for(int i=1;i<=4e6;i++) h[i]=1ll*h[i-1]*i%mod;
	for(int i=2;i<=4e6;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=4e6;i++) finv[i]=1ll*finv[i-1]*inv[i]%mod;
}
int main() {
	Pre();
	scanf("%d%d",&n,&k);
	if(k==1) {puts("1");return 0;}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++) {
			if(!j) f[i][j]=f[i-1][j];
			else f[i][j]=(f[i-1][j]+1ll*f[i][j-1]*(n-j+1)%mod*C(n-i+(n-j+1)*(k-1)-1,k-2)%mod)%mod;
	}
	printf("%d\n",f[n][n]);
	return 0;
}