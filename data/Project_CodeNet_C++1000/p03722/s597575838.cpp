#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;
using lint=long long;

void bfs(const vector<vector<pair<int,lint>>>& G,int s,vector<bool>& vis){
	int n=G.size();
	vis[s]=true;
	queue<int> Q; Q.push(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(auto e:G[u]){
			int v=e.first;
			if(!vis[v]) vis[v]=true, Q.push(v);
		}
	}
}

pair<vector<lint>,bool> Bellman_Ford(const vector<vector<pair<int,lint>>>& G,int s){
	int n=G.size();
	vector<lint> d(n,1LL<<61);
	d[s]=0;
	rep(t,n){
		bool updated=false;
		rep(u,n) for(const auto& e:G[u]) {
			int v=e.first;
			lint cost=e.second;
			if(d[v]>d[u]+cost){
				d[v]=d[u]+cost;
				updated=true;
			}
		}
		if(t==n-1 && updated) return {d,false};
	}
	return {d,true};
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<vector<pair<int,lint>>> G(n),G_rev(n);
	rep(i,m){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c); u--; v--;
		G[u].emplace_back(v,-c);
		G_rev[v].emplace_back(u,-c);
	}

	vector<bool> vis(n),vis_rev(n);
	bfs(G,0,vis);
	bfs(G_rev,n-1,vis_rev);

	vector<int> p,f(n,-1);
	rep(u,n) if(vis[u] && vis_rev[u]) p.emplace_back(u);
	rep(i,p.size()) f[p[i]]=i;

	vector<vector<pair<int,lint>>> H(p.size());
	rep(u,n) if(f[u]!=-1) {
		for(auto e:G[u]){
			int v=e.first;
			if(f[v]!=-1) H[f[u]].emplace_back(f[v],e.second);
		}
	}

	vector<lint> dist;
	bool ok;
	tie(dist,ok)=Bellman_Ford(H,0);

	if(ok) cout<<-dist[f[n-1]]<<endl;
	else   cout<<"inf"<<endl;

	return 0;
}
