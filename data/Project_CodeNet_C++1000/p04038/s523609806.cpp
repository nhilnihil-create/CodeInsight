#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
const long long MAXN=2010;
long long n,k,dp[MAXN][MAXN];
long long fac[MAXN*MAXN],inv[MAXN*MAXN];
long long C(long long x,long long y){return fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	scanf("%lld%lld",&n,&k);
	fac[0]=1;for(register long long i=1;i<=n*k;i++)fac[i]=fac[i-1]*i%mod;
	inv[1]=1;for(register long long i=2;i<=n*k;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	inv[0]=1;for(register long long i=1;i<=n*k;i++)inv[i]=inv[i-1]*inv[i]%mod;
	if(k==1){
		printf("1\n");
		return 0;
	}
	dp[0][0]=1;
	for(register long long i=1;i<=n;i++){
		for(register long long j=0;j<=i;j++){
			dp[i][j]=dp[i-1][j];
			if(j)dp[i][j]=(dp[i][j]+(n-j+1)*dp[i][j-1]%mod*C(n*k-i-(k-1)*(j-1)-1,k-2)%mod)%mod;			
		}
	}
	printf("%lld\n",dp[n][n]);
	return 0;
} 