#include<bits/stdc++.h>

using namespace std;

#define N 120000

int n,f[N];
vector<int> g[N];

void dfs(int u,int fa){
	for (int v:g[u])
		if (v!=fa){
			dfs(v,u);
			f[u]^=f[v];
		}
	++f[u];
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		g[x].push_back(y); g[y].push_back(x);
	}
	dfs(1,0);
	puts(f[1]>1?"Alice":"Bob");
	
	return 0;
}
			