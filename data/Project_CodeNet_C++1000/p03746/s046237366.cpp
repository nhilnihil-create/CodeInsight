#include <bits/stdc++.h>
using namespace std;

int n, m;
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
		--e.from;
		--e.to;
		g[e.from].push_back(e);
		if(!D){
			swap(e.from, e.to);
			g[e.from].push_back(e);
		}
	}
}
int f[100010];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	Graph g(n);
	readGraph(g, m, false, false);
	memset(f, -1, sizeof(f));
	int p = 0, q = g[0][0].to;
	f[p] = q;
	f[q] = n;
	while(1){
		bool t = true;
		for(int i=0; i<g[p].size(); ++i){
			if(f[g[p][i].to] == -1){
				f[g[p][i].to] = p;
				p = g[p][i].to;
				t = false;
				break;
			}
		}
		if(t) break;
	}
	while(1){
		bool t = true;
		for(int i=0; i<g[q].size(); ++i){
			if(f[g[q][i].to] == -1){
				f[q] = g[q][i].to;
				f[g[q][i].to] = n;
				q = g[q][i].to;
				t = false;
				break;
			}
		}
		if(t) break;
	}
//	for(int i=0; i<n; ++i) cout << i << " " << f[i] << "\n";
//	cout << p << " " << q << "\n";
	int cnt = 0;
	for(int i=0; i<n; ++i)
		if(f[i] != -1)
			++cnt;
	cout << cnt << "\n";
	for(int i=p; i!=n; i=f[i]) cout << i+1 << " \n"[f[i]==n];
}