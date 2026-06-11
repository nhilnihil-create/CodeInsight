#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 2005;
vector<int> g[N];
int dist[N][N];

void dfs(int v, int p, int __dist, int rt){
	dist[rt][v] = __dist;
	for(auto u : g[v]){
		if(u != p)dfs(u, v, __dist + 1, rt);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, k;
	cin>>n>>k;
	for(int i = 1; i < n; i++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i <= n; i++){
		dfs(i, 0, 0, i);
	}
	int ans = n;
	if(k&1){
		for(int rt = 1; rt <= n; rt++){
			for(int rrt : g[rt]){
				int tmp = n;
				for(int v = 1; v <= n; v++){
					if(dist[rt][v] <= k/2 || dist[rrt][v] <= k/2)tmp--;
				}
				ans = min(ans, tmp);
			}
		}
	}else{
		for(int rt = 1; rt <= n; rt++){
			int tmp = n;
			for(int v = 1; v <= n; v++){
				if(dist[rt][v] <= k/2)tmp--;
			}
			ans = min(ans, tmp);
		}
	}
	cout<<ans<<endl;

	return 0;
}