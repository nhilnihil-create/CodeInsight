#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 2000
#define MO 1000000007
using namespace std;
int dp[MAXN+5][MAXN+5];
int fact[MAXN*MAXN+5],inv[MAXN*MAXN+5];
int PowMod(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1)
			ret=1LL*ret*a%MO;
		a=1LL*a*a%MO;
		b>>=1;
	}
	return ret;
}
void prepare()
{
	fact[0]=1;
	for(int i=1;i<=MAXN*MAXN;i++)
		fact[i]=1LL*fact[i-1]*i%MO;
	inv[MAXN*MAXN]=PowMod(fact[MAXN*MAXN],MO-2);
	for(int i=MAXN*MAXN-1;i>=0;i--)
		inv[i]=1LL*inv[i+1]*(1LL*i+1LL)%MO;
}
int C(int n,int m)
{
	if(n<m)
		return 0;
	return 1LL*fact[n]*inv[m]%MO*inv[n-m]%MO;
}
int main()
{
//	freopen("ball.in","r",stdin);
//	freopen("ball.out","w",stdout);
	int N,K;
	scanf("%d %d",&N,&K);
	if(K==1)
	{
		printf("1\n");
		return 0;
	}
	dp[0][0]=1;
	prepare();
	for(int i=0;i<=N;i++)
		for(int j=0;j<=i;j++)
		{
			if(i-1>=0)
				dp[i][j]=(1LL*dp[i][j]+1LL*dp[i-1][j])%MO;
			if(j-1>=0)
			dp[i][j]=(1LL*dp[i][j]+1LL*dp[i][j-1]*C(N*K-(K-1)*(j-1)-i-1,K-2)%MO)%MO;
		}
	int ans=1LL*dp[N][N]*fact[N]%MO;
	printf("%d\n",ans);
	return 0;
}