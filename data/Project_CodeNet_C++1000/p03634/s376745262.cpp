#include <bits/stdc++.h>
#define MAXN 100000
#define inf LONG_MAX
using namespace std;
long long d[MAXN];
bool mark[MAXN];
void dijkstra(vector<pair<int,int>> *adj, int v, int n){
	fill(d,d + n, inf);
	fill(mark, mark + n, false);
	d[v] = 0;
	int u;
	priority_queue<pair<int,int>,vector<pair<int,int> >, less<pair<int,int> > > pq;
	pq.push({d[v], v});
	while(!pq.empty()){
		u = pq.top().second;
		pq.pop();
		if(mark[u])
			continue;
		mark[u] = true;
		for(auto p : adj[u]) //adj[v][i] = pair(vertex, weight)
			if(d[p.first] > d[u] + p.second){
				d[p.first] = d[u] + p.second;
				pq.push({d[p.first], p.first});
			}
	}
}
int main() {
  int N,Q,K,a,b,c,x,y;
  cin >> N;
  vector<pair<int,int>> G[N];
  x = N;
  while (--N) {
    cin >> a >> b >> c;
    G[--a].push_back({--b,c});
    G[b].push_back({a,c});
  }
  N = x;
  cin >> Q >> K;
  dijkstra(G,--K,N);
  while (Q--) {
    cin >> x >> y;
    cout << d[--x]+d[--y] << endl;
  }
}