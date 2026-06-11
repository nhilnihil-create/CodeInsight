#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,sg[N];
vector<int> e[N];
void dfs(int x,int fa){
	for (int i=0;i<e[x].size();i++){
		int v=e[x][i];
		if (v==fa) continue;
		dfs(v,x);
		sg[x]^=(sg[v]+1);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	puts(sg[1]?"Alice":"Bob");
	return 0;
}