#include <bits/stdc++.h>

using namespace std;

int n,k,l;

class graph{
public:
	int n, comp=0;
	vector<vector<int>> g, cl;
	vector<int> c, vis;
	
	graph(int n):n(n){
		g.resize(n);
		c.resize(n);
		vis.resize(n,0);
	}
	
	void addedge(int u, int v){
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	void dfs(int u){
		vis[u]=1;
		c[u]=comp;
		cl[comp].push_back(u);
		for(auto v:g[u]){
			if(!vis[v]){
				dfs(v);
			}
		}
	}
	
	void solve(){
		for(int i=0;i<n;i++){
			if(!vis[i]){
				cl.emplace_back();
				dfs(i);
				comp++;
			}
		}
	}
	
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k >> l;
	graph gk(n),gl(n);
	
	for(int i=0,u,v;i<k;i++){
		cin >> u >> v;
		u--,v--;
		gk.addedge(u,v);
	}
	for(int i=0,u,v;i<l;i++){
		cin >> u >> v;
		u--,v--;
		gl.addedge(u,v);
	}
	
	gk.solve();
	gl.solve();
	
	vector<int> ans(n,0);
	
	for(int i=0;i<gk.comp;i++){
		map<int,int> mp;
		for(auto u:gk.cl[i]){
			mp[gl.c[u]]++;
		}
		
		for(auto u:gk.cl[i]){
			ans[u]=mp[gl.c[u]];
		}
	}
	
	for(auto v:ans){
		cout << v << " ";
	}
	cout << endl;
	
	return 0;
}