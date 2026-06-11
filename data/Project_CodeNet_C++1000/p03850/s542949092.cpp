#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long dp[maxn][3];
int n;
int val[maxn],pos[maxn];
char op[3];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&val[i]);
		if(i!=n)
		{
			scanf("%s",op+1);
			if(op[1]=='+')pos[i+1]=0;
			else pos[i+1]=1;		
		}
	}
	memset(dp,128,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		if(pos[i])
		{
			dp[i][0]=max(dp[i-1][0]-val[i],max(dp[i-1][1]+val[i],dp[i-1][2]-val[i]));
			dp[i][1]=max(dp[i-1][0]-val[i],max(dp[i-1][1]+val[i],dp[i-1][2]-val[i]));
			dp[i][2]=max(dp[i-1][1]+val[i],dp[i-1][2]-val[i]);
		}
		else 
		{
			dp[i][0]=max(max(dp[i-1][1]-val[i],dp[i-1][2]+val[i]),dp[i-1][0]+val[i]);
			dp[i][1]=max(dp[i-1][1]-val[i],dp[i-1][2]+val[i]);
			dp[i][2]=dp[i-1][2]+val[i];
		}
	}
	printf("%lld\n",dp[n][0]);
}