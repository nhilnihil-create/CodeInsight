#include<cstdio>
#include<iostream>
#include<cstring>
#define RG register
#define LL long long
using namespace std;
const int N=2e3+10;
const LL mod=1e9+7;
int n,k,maxx;
LL inv[N*N]={0,1},fac1[N*N]={1},fac2[N*N]={1},dp[N][N];
LL C(int nn,int mm){return fac1[nn]*fac2[mm]%mod*fac2[nn-mm]%mod;}
int main()
{
	//freopen(".in","r",stdin);
	scanf("%d%d",&n,&k); maxx=n*k;
	if(k==1) { printf("1\n"); return 0; }
	for(RG int i=1;i<=maxx;i++) fac1[i]=fac1[i-1]*i%mod;
	for(RG int i=2;i<=maxx;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(RG int i=1;i<=maxx;i++) fac2[i]=fac2[i-1]*inv[i]%mod;
	dp[0][0]=1;
	for(RG int i=1;i<=n;i++)
	 for(RG int j=0;j<=i;j++)//
	  dp[i][j]=(dp[i-1][j]+(j!=0)*C(n-i+(n-j+1)*(k-1)-1,k-2)*dp[i][j-1]%mod*(n-j+1)%mod)%mod;
	printf("%lld",dp[n][n]);
	return 0;
}