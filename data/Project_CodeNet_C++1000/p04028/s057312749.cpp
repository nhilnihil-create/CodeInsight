#include<bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
long long n,l,b,dp[2][10005];
string s;
int main()
{
	cin>>n>>s;
	l=s.size();b=0;
	dp[b^1][0]=1;
	for(int i=1;i<=n;i++,b^=1)for(int j=0;j<=l+n;j++)if(!j)dp[b][j]=(dp[b^1][j]+dp[b^1][j+1]*2)%md;else dp[b][j]=(dp[b^1][j-1]+dp[b^1][j+1]*2)%md;
	printf("%lld\n",dp[b^1][l]);
	return 0;
}