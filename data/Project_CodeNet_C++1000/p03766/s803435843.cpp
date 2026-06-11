#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<stack>
using namespace std;
typedef long long ll;
#define N 1000015
const int p=1e9+7;
int n,dp[N],s[N];
int main()
{
	scanf("%d",&n);
	dp[n]=n;s[n]=n;
	dp[n-1]=1ll*n*n%p;s[n-1]=(s[n]+dp[n-1])%p;
	for(int i=n-2;i>0;i--)
	{
		dp[i]=(dp[i]+dp[i+1])%p;
		dp[i]=(dp[i]+1ll*(n-1)*(n-1)%p)%p;
		dp[i]=(dp[i]+s[i+3])%p;
		dp[i]=(dp[i]+i+1)%p;
		s[i]=(s[i+1]+dp[i])%p;
	}
	printf("%d\n",dp[1]);
}
