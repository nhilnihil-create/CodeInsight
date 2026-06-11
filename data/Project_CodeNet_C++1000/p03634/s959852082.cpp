// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

typedef pair<int, int> Edge;
typedef pair<int, int> P;

int main() {
  int n; cin >> n;
  vector<Edge> G[100000];
  loop(i,0,n-1) {
    int a, b, c; cin >> a >> b >> c;
    a--;b--;
    G[a].emplace_back(b, c);
    G[b].emplace_back(a, c);
  }
  int q, k; cin >> q >> k; k--;
  const ll INF = 100000000000000000;
  vector<ll> D(n, INF);
  {
    vector<bool> done(n, false);
    priority_queue<P> Q;
    Q.push({ 0, k });
    D[k] = 0;
    while (Q.size()) {
      auto p = Q.top(); Q.pop();
      int v = p.second;
      if (done[v]) continue;
      done[v] = true;
      for (auto &&edge: G[v]) {
        int u = edge.first, w = edge.second;
        if (done[u]) continue;
        if (D[u] > D[v] + w)  {
          D[u] = D[v] + w;
          Q.push({ D[u], u });
        }
      }
    }
  }
  
  while (q--) {
    int x, y; cin >> x >> y; x--;y--;
    cout << D[x] + D[y] << endl;
  }
  
  return 0;
}
