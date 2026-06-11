#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^'0');
		ch=getchar();
	}
	return x*f;
}
vector<int>G[MAXN];
inline void AddEdge(int u,int v){
	G[u].push_back(v);
}
int dfs(int u,int father){
	int ans=0;
	for (int i=0;i<G[u].size();++i){
		int v=G[u][i];
		if (v!=father) ans^=(dfs(v,u)+1);
	}
	return ans;
}
int main(){
	int n=read();
	int cnt=0;
	for (int i=1;i<n;++i){
		int u=read(),v=read();
		AddEdge(u,v);
		AddEdge(v,u);
	}
	puts(dfs(1,1)?"Alice":"Bob");
}