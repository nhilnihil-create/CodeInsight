#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,x;char op;ll dp[3],nxt[3];

int main()
{
	scanf("%d%d",&n,&dp[0]);
	dp[1]=dp[2]=-1ll<<60;
	for(int i=1;i<n;i++)
	{
		scanf(" %c%d",&op,&x);
		if(op=='-') x=-x;
		nxt[0]=dp[0]+x,nxt[1]=dp[1]-x,nxt[2]=dp[2]+x;
		dp[0]=max(nxt[0],max(nxt[1],nxt[2]));
		if(op=='+') dp[1]=max(nxt[1],nxt[2]),dp[2]=nxt[2];
		else dp[1]=dp[0],dp[2]=max(nxt[1],nxt[2]);
	}
	printf("%lld",dp[0]);
	return 0;
}