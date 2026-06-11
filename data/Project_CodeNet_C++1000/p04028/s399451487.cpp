#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 5005
#define MO 1000000007
#define LL long long
char s[MAXN];
LL dp[MAXN][MAXN];
LL qsm(LL a,LL b)
{
	LL ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%MO;
		a=a*a%MO;
		b>>=1;
	}
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	int len=strlen(s);
	LL inv=qsm(2,MO-2);
	inv=qsm(inv,len);
	dp[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			if(dp[i][j]!=0)
			{
				dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*2%MO)%MO;
				if(j==0) dp[i+1][0]=(dp[i+1][0]+dp[i][j])%MO;
				else dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%MO;
			}
	printf("%lld\n",dp[n][len]*inv%MO);
}