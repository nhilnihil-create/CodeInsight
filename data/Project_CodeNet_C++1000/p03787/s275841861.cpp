#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100050;
int fa[maxn*2];
int find(int x) {
	return x==fa[x]?x:(fa[x]=find(fa[x]));
}
void join(int x,int y,int& blk) {
	x=find(x),y=find(y);
	if(x!=y) --blk,fa[x]=y;
}
pair<int,int> data[maxn*2];
vector<int> G[maxn];
int vis[maxn];
bool flag;
void dfs(int x,int col) {
	if(vis[x]) {
		if(vis[x]!=col) flag=false;
		return;
	}
	vis[x]=col;
	for(auto v:G[x]) {
		dfs(v,3-col);
	}
}
int main() {
	int n,m;
	scanf("%d%d", &n,&m);
	for(int i = 0; i < m; ++i) {
		int x,y;
		scanf("%d%d", &x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
		data[i]={x,y};
	}
	int u=0,v=0;
	for(int i = 1; i <= n; ++i) {
		if(G[i].size()) ++u;
		else ++v;
	}
	iota(fa,fa+n*2+1,0);
	int blk1=u*2;
	for(int i = 0; i < m; ++i) {
		int x=data[i].first,y=data[i].second;
		join(x,y+n,blk1);
		join(x+n,y,blk1);
	}
	int blk2=blk1;
	for(int i = 0; i < m; ++i) {
		int x=data[i].first,y=data[i].second;
		join(x,y,blk2);
	}
	ll ans=0;
	for(int i = 1; i <= n; ++i) {
		if(!G[i].size() || vis[i]) continue;
		flag=true;
		dfs(i,1);
		if(flag) ans+=blk1;
		else ans+=blk2;
	}
	ans+=((ll)v*n+(ll)u*v);
	cout<<ans<<endl;
	return 0;
}
