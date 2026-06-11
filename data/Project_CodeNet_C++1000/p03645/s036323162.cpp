#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}


constexpr ll INF = 10000000000000000;

struct Edge {
  ll to;
  ll cost;
};

// dijkstra's法 O(|V|log|E|)
using P = pair<ll, ll>;
vector<ll> dijkstra(
  vector<vector<Edge>> const& graph,
  ll const s,
  ll const n
)
{
  vector<ll> d(n+1, INF);
  d[s] = 0;
  priority_queue<P, vector<P>, std::greater<P>> que;
  // (cost, vertex)
  que.push(make_pair(0, s));

  while (!que.empty()) {
    P e = que.top();
    que.pop();

    if (d[e.second] < e.first) continue;
    for (auto itr : graph[e.second]) {
      if (d[itr.to] > d[e.second] + itr.cost) {
        d[itr.to] = d[e.second] + itr.cost;
        que.push(P(d[itr.to], itr.to));
      }
    }
  }
  return d;
}
/*
int main() {
  int n, e;
  cin >> n >> e;
  vector<vector<Edge>> graph(n+1);

  for (int i = 0; i < e; ++i) {
    int to, from, cost;
    cin >> from >> to >> cost;
    graph[to].push_back({from, cost});
    graph[from].push_back({to, cost});
  }

  auto d = dijkstra(graph, 0, n);

  for (int i = 0; i < n; ++i) {
    cout << "shortest cost " << i << " " << d[i] << endl;
  }
}*/

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,M;
  cin >> N >> M;
  vector<vector<Edge>> G(N+1);
  repr(i, M, 0) {
    int a,b;
    cin >> a >> b;
    G[a].push_back({b, 1});
    G[b].push_back({a, 1});
  }

  auto d = dijkstra(G, 1, N);
  if (d[N] == 2) {
    cout << "POSSIBLE"<< endl;
  } else {
    cout << "IMPOSSIBLE"<< endl;
  }
}