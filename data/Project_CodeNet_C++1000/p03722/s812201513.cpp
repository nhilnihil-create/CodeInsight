#include <bits/stdc++.h>

using namespace std;

template <class T>
using lim = numeric_limits<T>;

typedef long long ll;
typedef long double ld;

struct edge {
	int here;
	int there;
	int w;
};

// solve for min-path
// bellman-ford
pair<vector<ll>,vector<bool>> solve(vector<edge> myEdges, int n, int start){
	vector<ll> dist(n, lim<ll>::max());
	vector<bool> cycle(n, false);
	
	dist[start] = 0;
	
	for (int count = 0; count < n - 1; count ++){
		for (int i = 0; i < (int) myEdges.size(); i++){
			int u = myEdges[i].here;
			int v = myEdges[i].there;
			int w = myEdges[i].w;
			if (dist[u] == lim<ll>::max()) continue;
			if (dist[u] + w < dist[v]){
				dist[v] = dist[u]+w;
			}
		}
	}
	
	for (int count = 0; count < n; count++){
		for (int i = 0; i < (int) myEdges.size(); i++){
			int u = myEdges[i].here;
			int v = myEdges[i].there;
			int w = myEdges[i].w;
			if (dist[u] == lim<ll>::max()) continue;
			if (dist[u] + w < dist[v]) cycle[v] = true;
			
			if (cycle[u]) cycle[v] = true;
		}
	}
	
	return make_pair(dist,cycle);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector<vector<bool>> isEdge(n, vector<bool>(n,0));
	// grabbing cost matrix
	vector<edge> myEdges(m);
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		isEdge[a-1][b-1] = true;
		myEdges[i].here = a-1;
		myEdges[i].there = b- 1;
		myEdges[i].w = -c;
	}
	
	
	auto ans = solve(myEdges, n, 0);
	if (ans.second[n-1]) cout << "inf" << endl;
	else cout << -ans.first[n-1] << endl;
}
