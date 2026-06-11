#include<iostream>
#include<algorithm>
using namespace std;
long dp[1<<17][3],a;
char op;
int n;
main()
{
	cin>>n>>dp[0][0];
	dp[0][1]=dp[0][2]=-1e18;
	for(int i=1;i<n;i++)
	{
		cin>>op>>a;
		if(op=='+')
		{
			for(int j=0;j<3;j++)dp[i][j]=dp[i-1][j]+(j%2?-a:a);
		}
		else
		{
			dp[i][0]=dp[i-1][0]-a;
			dp[i][1]=max(dp[i-1][1]+a,dp[i-1][0]-a);
			dp[i][2]=max(dp[i-1][2]+a,dp[i-1][1]+a);
		}
	}
	cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;
}
