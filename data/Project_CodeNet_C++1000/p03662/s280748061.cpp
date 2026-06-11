#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 10e8
#define rep(i,n) for(int i=0; i<n; i++)
#define repr(i,n,m) for(int i=m; i<n; i++)
#define MAX 100
#define MOD 1000000007
#define pb push_back
#define debug(x) cout << x << endl;
#define END cout << endl;
#define sorti(x) sort(x.begin(), x.end())

/* ダイクストラ法, vector gにedgeを入れます */
typedef pair<int, int> P; // firstは最短距離, secondは頂点の番号
typedef struct edge {int to, cost;} edge;
vector<edge> g[100002];
int d[100001];
int V; //頂点の数を入れること

void dijkstra(int s) {
  priority_queue<P,vector<P>,greater<P> > que;
  for (int i = 0; i <= V; ++i) d[i] = INF;
  d[s] = 0;
  que.push(P(0,s));

  while (!que.empty()) {
    P p = que.top(); que.pop();
    int v = p.second;

    if (d[v] < p.first) continue;

    for (int i = 0; i < g[v].size(); ++i) {
      edge e = g[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main() {
  int n,a,b; cin >> V;
  rep(i,V-1) {
    cin >> a >> b;
    g[a].pb({b,1});
    g[b].pb({a,1});
  }
  vector<int> cost1(V+1), cost2(V+1);
  int cnt1 = 0, cnt2 = 0;
  
  dijkstra(1);
  rep(i,V+1) {
    cost1[i] = d[i];
  }
  dijkstra(V);
  rep(i,V+1) {
    cost2[i] = d[i];
  }
  
  repr(i,V+1,1) {
    if (cost1[i] <= cost2[i]) cnt1 += 1; else cnt2 += 1;
  }
  
  printf((cnt1 > cnt2) ? "Fennec" : "Snuke");
}