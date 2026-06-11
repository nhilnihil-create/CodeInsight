#include<iostream>
#include<cstring>
#include<cstdio>
#define mod 1000000007
using namespace std;
long long dp[5010][5010];
char s[5010];
void rw(long long &a,long long b){a=(a+b)%mod;}
int main()
{
	int n;scanf("%d%s",&n,s);
	int m=strlen(s);dp[0][0]=1;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=i;j++)
	{
		rw(dp[i+1][max(0,j-1)],dp[i][j]);
		rw(dp[i+1][j+1],2*dp[i][j]);
	}
	for(int i=1;i<=m;i++)dp[n][m]=dp[n][m]*500000004%mod;
	printf("%lld\n",dp[n][m]);return 0;
}