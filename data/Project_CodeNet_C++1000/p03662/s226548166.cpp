#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> prev(n, -1);
	queue<pair<int, int>> q{{{0, 0}}};
	while(!q.empty()){
		int u, p;
		tie(u, p) = q.front(); q.pop();
		for(auto v: adj[u]){
			if(v != p){
				prev[v] = u;
				q.push({v, u});
			}
		}
	}
	vector<int> path, visited(n);
	for(auto u = n - 1; ~u; u = prev[u]){
		path.push_back(u);
		visited[u] = true;
	}
	reverse(path.begin(), path.end());
	int res = 0;
	for(auto i = 0, j = int(path.size()) - 1; i <= j; ++ i, -- j){
		function<void(int, int)> dfs = [&](int u, int delta){
			visited[u] = true;
			res += delta;
			for(auto v: adj[u]){
				if(!visited[v]){
					dfs(v, delta);
				}
			}
		};
		dfs(path[i], 1);
		if(i != j) dfs(path[j], -1);
	}
	res > 0 ? cout << "Fennec\n" : cout << "Snuke\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////