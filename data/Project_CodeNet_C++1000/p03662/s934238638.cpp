#include <bits/stdc++.h>

using namespace std;

#define debug(x) '[' << #x << " is: " << x << "] "
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int nax = 1e5 + 100;

vector<int> g[nax];
int sz[nax],par[nax],depth[nax];

void dfs(int u,int p){
	par[u] = p;
	sz[u] = 1;
	for(int v : g[u]){
		if(v == p)continue;
		depth[v] = depth[u] + 1;
		dfs(v,u);
		sz[u] += sz[v];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	#ifndef ONLINE_JUDGE
	//	freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int u = n;
	for(int i=0;i<(depth[n]-1)/2;i++){
		u = par[u];
	}
	// cout << n-sz[u] << ' ' << sz[u] << endl;
	cout << (n - sz[u] > sz[u] ? "Fennec" : "Snuke") << '\n';
}