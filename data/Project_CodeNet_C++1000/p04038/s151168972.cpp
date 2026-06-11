#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 2000
#define MAXM 4000000
#define MO 1000000007
int dp[MAXN+5][MAXN+5],n,k;
int fac[MAXM+5],inv[MAXM+5];
int PowMod(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1) ret=1LL*ret*a%MO;
		a=1LL*a*a%MO;
		b>>=1;
	}
	return ret;
}
int C(int n,int m)
{
	return 1LL*fac[n]*inv[m]%MO*inv[n-m]%MO;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<=MAXM;i++)
		fac[i]=1LL*fac[i-1]*i%MO;
	inv[MAXM]=PowMod(fac[MAXM],MO-2);
	for(int i=MAXM-1;i>=0;i--)
		inv[i]=1LL*inv[i+1]*(i+1)%MO;
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		printf("1\n");
		return 0;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j!=0)
				dp[i][j]+=1LL*dp[i][j-1]*C(n*k-i-(k-1)*(j-1)-1,k-2)%MO;
			dp[i][j]%=MO;
		}
	int ans=1LL*dp[n][n]*fac[n]%MO;
	printf("%d\n",ans);
}