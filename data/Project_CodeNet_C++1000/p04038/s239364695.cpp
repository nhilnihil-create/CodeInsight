#include <cstdio>
#define rr register
using namespace std;
const int mod=1000000007,N=2001;
int n,k,inv[N*N],fac[N*N],dp[N][N];
inline signed mo(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline signed c(int n,int m){return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
signed main(){
	inv[0]=inv[1]=fac[0]=fac[1]=1,scanf("%d%d",&n,&k);
	if (k==1) return !putchar(49);
	for (rr int i=2;i<=n*k;++i) inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
	for (rr int i=2;i<=n*k;++i) fac[i]=1ll*fac[i-1]*i%mod,inv[i]=1ll*inv[i-1]*inv[i]%mod;
	for (rr int i=0;i<=n;++i) dp[i][0]=1;
	for (rr int i=1;i<=n;++i) for (rr int j=1;j<=i;++j)
	    dp[i][j]=mo(dp[i-1][j],1ll*dp[i][j-1]*(n-j+1)%mod*c(n*k-i-1-(j-1)*(k-1),k-2)%mod);
	return !printf("%d\n",dp[n][n]);
}