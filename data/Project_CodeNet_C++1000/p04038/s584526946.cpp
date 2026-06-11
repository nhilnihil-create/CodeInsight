#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
const int mod=1e9+7,N=2005;
int n,k,f[N][N],fac[N*N],inv[N*N],infac[N*N];
int C(int a,int b)	{return fac[a]*infac[b]%mod*infac[a-b]%mod;}
signed main(){
	scanf("%lld%lld",&n,&k);
	if(k==1){
		printf("1\n");
		return 0;
	}
	fac[0]=infac[0]=inv[1]=1;
	for(int i=2;i<=n*k;i++)	inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n*k;i++)	fac[i]=fac[i-1]*i%mod,infac[i]=infac[i-1]*inv[i]%mod;
	for(int i=1;i<=n;i++)	f[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i][j]+=(f[i-1][j]+C(k*n-i-(j-1)*(k-1)-1,k-2)*f[i][j-1]%mod*(n-j+1)%mod)%mod;
	printf("%lld\n",f[n][n]);
	return 0;
}