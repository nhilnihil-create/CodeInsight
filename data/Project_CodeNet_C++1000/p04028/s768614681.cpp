#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
const int inv2=500000004;
char s[5050];
int dp[2][5050];
int main()
{
	int n,l,now,to;
	scanf("%d",&n);
	scanf("%s",s);
	l=strlen(s);
	memset(dp,0,sizeof(dp));
	now=0;
	to=1;
	dp[now][0]=1;
	for(int i=0;i<n;i++)
	{
		dp[to][1]=((long long)dp[now][0]*2+dp[to][1])%mod;
		(dp[to][0]+=dp[now][0])%=mod;
		dp[now][0]=0;
		for(int j=1;j<=i;j++)
			if(dp[now][j])
			{
				dp[to][j+1]=((long long)dp[now][j]*2+dp[to][j+1])%mod;
				(dp[to][j-1]+=dp[now][j])%=mod;
				dp[now][j]=0;
			}
		swap(now,to);
	}
	int ans=dp[now][l];
	for(int i=0;i<l;i++)
		ans=(long long)ans*inv2%mod;
	printf("%d",ans);
	return 0;
}