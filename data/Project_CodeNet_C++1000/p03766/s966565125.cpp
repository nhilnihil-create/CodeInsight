#include<bits/stdc++.h>
using namespace std;
const int md=1e9+7;
int dp[1000005];
int main()
{
	int n,sum;
	scanf("%d",&n);
	dp[0]=0;
	dp[1]=n;
	dp[2]=1ll*n*n%md;
	sum=(dp[1]+dp[2])%md;
	for(int i=3;i<=n;i++)
	{
		dp[i]=1ll*(n-1)*(n-1)%md;
		dp[i]=(dp[i]+sum)%md;
		dp[i]=(dp[i]-dp[i-2]+md)%md;
		dp[i]=(dp[i]+n-i+2)%md;
		sum=(sum+dp[i])%md;
	}
	printf("%d\n",dp[n]);
	return 0;
}