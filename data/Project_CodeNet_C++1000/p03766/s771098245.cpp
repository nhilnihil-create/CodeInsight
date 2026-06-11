#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int add(int x,int y){return x+y<mod?x+y:x+y-mod;}
int n;
int dp[2000200];
int suf[2000200];
int main()
{
	scanf("%d",&n);
	for(int i=n+1;i<=n*2+10;++i)dp[i]=1;
	for(int i=n*2+10;i>n;--i)suf[i]=suf[i+1]+1;
	dp[n]=n;suf[n]=suf[n+1]+n;
	for(int i=n-1;i;--i)
	{
		dp[i]=add(dp[i],dp[i+1]);
//		cout<<dp[i]<<endl;
		dp[i]=add(dp[i],1ll*(n-1)*(n-1)%mod);
//		cout<<dp[i]<<endl;
		dp[i]=add(dp[i],add(suf[i+3],mod-suf[i+n+2]));
//		cout<<dp[i]<<endl;
		suf[i]=add(dp[i],suf[i+1]);
	}
	printf("%d\n",dp[1]);
	return 0;
}
