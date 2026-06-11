#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=2005;
const int M=4000005;
const int mod=1000000007;

int n,m,ans;
int dp[N][N],fac[M],inv[M];

int quickpow(int x,int y){
	int s=1;
	for (;y;y>>=1,x=1ll*x*x%mod)
		if (y&1) s=1ll*s*x%mod;
	return s;
}

void init(int n){
	int i,j;
	fac[0]=inv[0]=1;
	for (i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=quickpow(fac[n],mod-2);
	for (i=n-1;i;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}

int C(int x,int y){
	if (x<y) return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}

int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	if (m==1){
		printf("1\n");
		return 0;
	}
	init(M-5);
	dp[0][0]=1;
	for (i=0;i<=n;i++)
		for (j=0;j<=i;j++) if (dp[i][j]){
			(dp[i][j+1]+=dp[i][j])%=mod;
			(dp[i+1][j]+=1ll*dp[i][j]*C(i*(m-1)+j+m-2,m-2)%mod)%=mod;
		}
	ans=dp[n][n];
	for (i=1;i<=n;i++) ans=1ll*ans*i%mod;
	printf("%d\n",ans); 
	return 0;
} 