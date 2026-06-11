#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define mod 1000000007
using namespace std;
inline int read()
{
	char c=getchar(); int num=0,f=1;
	while (c<'0'||c>'9') { if (c=='-') f=-1; c=getchar(); }
	while (c<='9'&&c>='0') { num=num*10+c-'0'; c=getchar(); }
	return num*f;
}
int n,m,dp[5005][5005],ans;
char s[5005];
int ksm(int a,int b)
{
	int ret=1;
	for (;b;b>>=1,a=1ll*a*a%mod)
	 if (b&1) ret=1ll*ret*a%mod;
	return ret;
}
int main()
{
	n=read(); scanf("%s",s+1); m=strlen(s+1);
	dp[0][0]=1;
	for (int i=0;i<n;i++)
	 for (int j=0;j<=i;j++) if (dp[i][j])
	 {
		 dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*2%mod)%mod;
		 dp[i+1][max(j-1,0)]=(dp[i+1][max(j-1,0)]+dp[i][j])%mod;
	 }
	ans=1ll*dp[n][m]*ksm(ksm(2,m),mod-2)%mod;
	printf("%d",ans);
	return 0;
}