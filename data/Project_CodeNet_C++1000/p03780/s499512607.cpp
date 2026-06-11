#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
int Dp[N][N],dp[N][N];
int n,k,x[N];
bool check(int mid)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<k;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(i!=mid&&j-x[i]>=0)dp[i][j]+=dp[i-1][j-x[i]];
		}
	}
	for(int i=0;i<k;i++)
	{
		if(dp[n][i]&&i+x[mid]>=k)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>x[i];
	sort(x+1,x+1+n);
	dp[0][0]=1;
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<r<<endl;
	return 0;
}