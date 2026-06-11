#include<cstdio>
#define mod 1000000007
#define maxn 2005
int n,k,fact[maxn*maxn],inv[maxn*maxn],dp[maxn][maxn];
void init()
{
	fact[0]=1;
	for(int i=1;i<=n*k;i++) fact[i]=1ll*fact[i-1]*i%mod;
	inv[1]=1;
	for(int i=2;i<=n*k;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	inv[0]=1;
	for(int i=1;i<=n*k;i++) inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
int main()
{
	scanf("%d%d",&n,&k);
	if(k==1) { printf("1\n"); return 0; }
	init();
	dp[0][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			if(i) dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
			if(j)
			{
				int x=n*k-i-(j-1)*(k-1)-1;
				dp[i][j]=(dp[i][j]+1ll*dp[i][j-1]*fact[x]%mod*inv[k-2]%mod*inv[x-k+2]%mod)%mod;
			}
		}
	int ans=1ll*dp[n][n]*fact[n]%mod;
	printf("%d\n",ans);
}