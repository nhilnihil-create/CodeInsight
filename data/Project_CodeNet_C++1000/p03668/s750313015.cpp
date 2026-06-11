#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
vector<int> bi[100005];
int n,m,i,j,dp[100005];
void dfs(int x,int fa)
{
	int i;
	for (i=0;i<bi[x].size();i++)
	{
		if (bi[x][i]==fa) continue;
		dfs(bi[x][i],x);
		dp[x]^=dp[bi[x][i]]+1;
	}
}
int main()
{
	cin>>n;
	for (i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	dfs(1,0);
	if (dp[1]) cout<<"Alice"; else cout<<"Bob";
	return 0;
}