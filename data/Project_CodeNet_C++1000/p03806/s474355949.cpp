#include<bits/stdc++.h>
using namespace std;
int a[50], b[50], c[50];
int dp[405][405];
const int inf=1e9;
int n,x,y;
int main()
{
	//dp[i][j] miinimum cost of mixture i j
	cin>>n>>x>>y;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];

	}
	
	for(int i=0;i<=400;i++ )
	for(int j=0;j<=400;j++)
	dp[i][j]=inf;
	
	dp[0][0]=0;
	
	for(int cur=0;cur<n;cur++)
	{
		for(int i=400;i>=a[cur];i--)
		for(int j=400;j>=b[cur];j--)
		dp[i][j]=min(dp[i][j], dp[i-a[cur]][j-b[cur]]+c[cur]);
	}
	
	int ans=inf;
	for(int i=1;max(x,y)*i<=400;i++)
	ans=min(ans, dp[i*x][i*y]);
	
	if(ans>1e8)cout<<-1;
	else cout<<ans;
	
}