#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=5005,MOD=1e9+7;
int n;
long long dp[MAXN][MAXN];
char s[MAXN];
long long ksm(long long x,long long y)
{
	long long k=1;
	while(y)
	{
		if(y&1)
			k=(k*x)%MOD;
		x=(x*x)%MOD;
		y>>=1;
	}
	return k;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	int len=strlen(s);
	if(n<len)
	{
		printf("0\n");
		return 0;
	}
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i+1][j+1]+=(2*dp[i][j])%MOD;
			dp[i+1][j+1]%=MOD;
			dp[i+1][(j-1)>0?(j-1):0]+=dp[i][j];
			dp[i+1][(j-1)>0?(j-1):0]%=MOD;
		}
	}
	long long ans=(dp[n][len]*ksm((1e9+8)/2,len))%MOD;
	printf("%lld\n",ans);
}