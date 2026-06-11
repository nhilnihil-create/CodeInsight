#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<P>> g(n);
  rep(i,m) {
    int u, v, c;
    cin >> u >> v >> c;
    u--; v--;
    g[u].emplace_back(make_pair(v, c));
    g[v].emplace_back(make_pair(u, c));
  }
  
  set<int> st;
  auto calc = [&](int s){
    priority_queue<P, vector<P>, greater<P>> que;
    vector<int> d(n, INF);
    vector<int> to(n, -1);
    d[s] = 0;
    que.push(make_pair(0, s));
    while (!que.empty()) {
      auto p = que.top(); que.pop();
      if (d[p.second] < p.first) continue;
      for (auto e : g[p.second]) {
        if (d[e.first] > d[p.second] + e.second) {
          d[e.first] = d[p.second] + e.second;
          to[e.first] = p.second;
          que.push(make_pair(d[e.first], e.first));
        }
      }
    }
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j != -1) {
        int a = j, b = to[j];
        if (a > b) swap(a, b);
        if (a != -1) st.insert(a * n + b);
        j = to[j];
      }
    }
  };


  for (int i = 0; i < n; i++) calc(i);
  cout << m - st.size() << endl;
  return 0;
}
