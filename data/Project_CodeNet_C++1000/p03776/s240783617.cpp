#include<bits/stdc++.h>
using namespace std;
long long dp[100][100],sum[100][100],a[100];
int n,l,r;
int main()
{
	cin>>n>>l>>r;
	for (int i=0;i<=n;i++)
	{
		sum[0][i]=0;
		sum[i][0]=1;
		sum[i][i]=1;
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		dp[i][0]=0;
		for (int j=1;j<=i&&j<=r;j++)
		{
			long long x=dp[i-1][j],y=dp[i-1][j-1]+a[i];
			if (x==y)
			{
				dp[i][j]=x;
				sum[i][j]=sum[i-1][j]+sum[i-1][j-1];
			}
			else if(x>y)
			{
				dp[i][j]=x;
				sum[i][j]=sum[i-1][j];
			}
			else
			{
				dp[i][j]=y;
				sum[i][j]=sum[i-1][j-1];
			}
		}
	}
	int pos=0;
	long long k=0;
	for (int i=l;i<=r&&i<=n;i++)
	{
		if(pos==0)
	     {
             pos=i;
             k=sum[n][i];
         }
         else if(dp[n][i]*pos>dp[n][pos]*i)
         {
            pos=i;
            k=sum[n][i];
         }
         else if(dp[n][i]*pos==dp[n][pos]*i)
         {
            k+=sum[n][i];
         }
	}
	printf("%.6f\n",dp[n][pos]*1.0/pos*1.0);
	cout<<k;
	return 0;
}