#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector<int> v, d, c;
class Edge{
public:
	long long cost;
	int from, to;
	Edge(long long c, int f, int t){
		cost = c;
		from = f;
		to = t;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
void readGraph(Graph &g, int E, bool D, bool C){ // E:NumofEdges, D:Directed, C:Costed
	for(int i=0; i<E; ++i){
		Edge e(0, 0, 0);
		if(!C) cin >> e.from >> e.to;
		else cin >> e.from >> e.to >> e.cost;
		g[e.from].push_back(e);
		if(!D){
			swap(e.from, e.to);
			g[e.from].push_back(e);
		}
	}
}
int ans[100010];
int rest[100010];
typedef pair<int, int> P;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n >> m;
	Graph g(n+1);
	readGraph(g, m, false, false);
	cin >> q;
	for(int i=0; i<q; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back(x);
		d.push_back(y);
		c.push_back(z);
	}
	for(int i=q-1; i>=0; --i){
		bool f = false;
		if(ans[v[i]] == 0){
			ans[v[i]] = c[i];
			rest[v[i]] = d[i];
			if(d[i] > 0) f = true;
		}else if(rest[v[i]] < d[i]){
			f = true;
		}
		if(!f) continue;
		queue<P> q;
		q.push(P(d[i], v[i]));
		while(!q.empty()){
			P p = q.front();
			q.pop();
//			cout << p.first << " " << p.second << "\n";
			for(int j=0; j<g[p.second].size(); ++j){
				if(ans[g[p.second][j].to] == 0){
					ans[g[p.second][j].to] = c[i];
				}else if(rest[g[p.second][j].to] >= p.first-1){
					continue;
				}
				rest[g[p.second][j].to] = p.first-1;
				if(p.first-1 > 0) q.push(P(p.first-1, g[p.second][j].to));
			}
		}
	}
	for(int i=1; i<=n; ++i)
		cout << ans[i] << "\n";
/*	for(int i=1; i<=n; ++i){
		cout << "from " << i << "\n";
		for(int j=0; j<g[i].size(); ++j)
			cout << g[i][j].to << (j+1 == g[i].size() ? "\n" : " ");
	}
*/
}