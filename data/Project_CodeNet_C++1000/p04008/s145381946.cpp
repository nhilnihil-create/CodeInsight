#include<iostream>
#include<cstdio>
#include<vector>
#define M 100010
using namespace std;
int n,k,ans,f[M],dp[M];
vector<int>S[M];
void dfs(int x) {
	dp[x]=1;
	for(int i=0;i<S[x].size();i++)
		dfs(S[x][i]),dp[x]=max(dp[x],dp[S[x][i]]+1);
	if(dp[x]==k&&x!=1&&f[x]!=1) ans++,dp[x]=0;
}
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&f[i]);
	if(f[1]!=1) ans++;
	for(int i=2;i<=n;i++) S[f[i]].push_back(i);
	dfs(1);printf("%d\n",ans);return 0;
}