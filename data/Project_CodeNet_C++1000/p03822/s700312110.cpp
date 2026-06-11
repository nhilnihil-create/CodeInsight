#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<int> G[MAXN];
int dp[MAXN];
int dfs(int x,int f)
{
	for(int v:G[x])
		if(v != f)
			dfs(v,x);
	
	static int tdp[MAXN];
	dp[x] = 0;
	int cnt = 0;
	for(int v:G[x])
		if(v != f)
			tdp[cnt++] = dp[v];
	sort(tdp,tdp+cnt,greater<int>());
	for(int i=0;i<cnt;i++)
		dp[x] = max(dp[x] , tdp[i]+i+1);
	return dp[x];
}
int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i=2;i<=n;i++) {
		int f;
		cin >> f;
		G[f].push_back(i);
	}
	cout << dfs(1,0) << endl;
}
