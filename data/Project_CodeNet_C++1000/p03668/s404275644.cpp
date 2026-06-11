#include<bits/stdc++.h>
#include<vector>
#define N 100005
using namespace std;
vector<int> G[N];
int n,f[N];
void dfs(int t,int fa)
{
	int i;
	for(i=0;i<G[t].size();i++)
		if(G[t][i]!=fa)
			dfs(G[t][i],t),f[t]^=(f[G[t][i]]+1);
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d %d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	  }
	dfs(1,0);
	printf(f[1] ? "Alice" : "Bob");
	return 0;
}
