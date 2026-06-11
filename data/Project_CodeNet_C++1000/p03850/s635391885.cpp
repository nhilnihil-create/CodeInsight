#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,dp[100005][3],num[100005];
char c[100005];
int main()
{
	cin>>n;
	c[1]='+';
	for (i=1;i<=n;i++)
	{
		if (i!=1) cin>>c[i];
		cin>>num[i];
	}
	dp[1][0]=num[1];
	dp[1][1]=dp[1][2]=-0x2222222222222222ll;
	for (i=2;i<=n;i++)
	{
		if (c[i]=='+')
		{
			dp[i][0]=max(dp[i-1][1],dp[i-1][0])+num[i];
			dp[i][1]=dp[i-1][1]-num[i];
			dp[i][2]=dp[i-1][2]+num[i];
		}
		else
		{
			dp[i][0]=-0x2222222222222222ll;
			dp[i][1]=max(dp[i-1][0],dp[i-1][1])-num[i];
			dp[i][2]=max(dp[i-1][1],dp[i-1][2])+num[i];
		}
	}
	cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
	return 0;
}