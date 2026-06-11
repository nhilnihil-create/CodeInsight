#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int dp[3000][51];
//dp[i][j] ways to take j cards and calculate sum
int32_t main()
{
	int n,a;
	cin>>n>>a;
	dp[0][0]=1;
	int x=0;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		for(int sum=2500;sum>=0;sum--)
			for(int cards=i;cards>=0;cards--)
			dp[sum+x][cards+1]+=dp[sum][cards];
	}

	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=dp[i*a][i];
	}
	cout<<ans<<"\n";
}

