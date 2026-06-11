#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,k,sum;
int a[N],dp[N][N];
bool check(int x)
{
	memset(dp,0,sizeof(dp));
	if(x==1)
	{
		dp[2][0]=1;
		dp[2][a[2]]=1;
		for(int i=3;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
			{
				dp[i][j]=dp[i-1][j];
				if(j>=a[i])
					dp[i][j]=dp[i-1][j]|dp[i-1][j-a[i]];	
			}
		}
	}
	else
	{
		dp[1][0]=1;
		dp[1][a[1]]=1;
		for(int i=2;i<=n;i++)
		{
			if(x==i)
			{
				for(int j=0;j<=k;j++)
					dp[i][j]=dp[i-1][j];
				continue;
			}
			for(int j=0;j<=k;j++)
			{
				dp[i][j]=dp[i-1][j];
				if(j>=a[i])
					dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i]];	
			}
		}
	}
	/*
	printf("x:%d\n",x);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)	
			printf("%d ",dp[i][j]);
		printf("\n");
	}
	*/
	for(int i=k-a[x];i<k;i++)
		if(dp[n][i])
			return true;
	return false;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);	
		a[i]=min(a[i],k);
	}
	if(n==1)
	{
		if(a[1]>=k)
			printf("0\n");
		else
			printf("1\n");
		return 0;
	}
	sort(a+1,a+n+1);
	int lb=0,ub=n+1;
	while(lb+1<ub)
	{
		int mid=(lb+ub)/2;
		if(check(mid))	
			ub=mid;
		else 
			lb=mid;
	}
	printf("%d\n",lb);
	return 0;
}
