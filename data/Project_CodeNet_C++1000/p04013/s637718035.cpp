#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[55][2555];
int main()
{
	int n,a;
	cin>>n>>a;
	int ar[n+1];
	for(int i=1;i<=n;i++)cin>>ar[i];
	dp[0][0]=1;
	ll t=0;
	for(int i=1;i<=n;i++)
	{
		for(int i2=i-1;i2>=0;i2--)
		{
			for(int j=t;j>=0;j--)
			{
				dp[i2+1][j+ar[i]]+=dp[i2][j];
			}
		}
		t+=ar[i];
	}
	ll res=0LL;
	for(int i=1;i<=n;i++)
	{
		res+=dp[i][i*a];
	}
	cout<<res;

}