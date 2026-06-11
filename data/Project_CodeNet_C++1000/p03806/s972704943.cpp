#include<bits/stdc++.h>
using namespace std;
int n,x,y,ans=1e8;
int a[50],b[50],c[50],dp[410][410];
int main(){
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>c[i];
	for(int i=0;i<=400;i++)
		for(int j=0;j<=400;j++)
			dp[i][j]=1e9;
	dp[0][0]=0;
	for(int l=1;l<=n;l++)
		for(int i=400;i>=a[l];i--)
			for(int j=400;j>=b[l];j--)
				dp[i][j]=min(dp[i][j],dp[i-a[l]][j-b[l]]+c[l]);
	for(int i=1;max(x,y)*i<=400;i++)
		ans=min(ans,dp[x*i][y*i]);
	if(ans>1e7)
		cout<<-1;
	else
		cout<<ans;
	return 0;
}