/*Lucky_Glass*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MOD=1e9+7;
int n;char str[5005];
long long dp[5005][5005];
int main()
{
	scanf("%d%s",&n,str);
	int len=strlen(str);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			if(n!=j)
				dp[j][i]+=2ll*dp[j+1][i-1];
			if(j)
				dp[j][i]+=dp[j-1][i-1];
			else
				dp[j][i]+=dp[j][i-1];
			dp[j][i]%=MOD;
		}
	printf("%lld\n",dp[len][n]);
	return 0;
}
