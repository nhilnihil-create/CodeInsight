#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
const int mod=1e9+7;
const int N=2001;
int dp[N][N],n,k;
int fac[N*N],inv[N*N];
inline int C(int n,int m){if(m>n)return 0;return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
inline int fpow(int x,int k){
	int ret=1;
	for(;k;k>>=1,x=1ll*x*x%mod) if(k&1) ret=1ll*ret*x%mod;return ret;
}
int main()
{
	scanf("%d %d",&n,&k);int tot=n*k;fac[0]=1;
	if(k==1) return puts("1"),0;
	for(int i=1;i<=tot;++i) fac[i]=1ll*fac[i-1]*i%mod;
	inv[tot]=fpow(fac[tot],mod-2);
	for(int i=tot-1;i;--i) inv[i]=1ll*inv[i+1]*(i+1)%mod;inv[0]=1;
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i;++j){
			dp[i][j]=dp[i-1][j];
			if(j) (dp[i][j]+=1ll*dp[i][j-1]*C(tot-i-1-(j-1)*(k-1),k-2)%mod*(n-j+1)%mod)%=mod;
		}
	printf("%d\n",dp[n][n]);
}
