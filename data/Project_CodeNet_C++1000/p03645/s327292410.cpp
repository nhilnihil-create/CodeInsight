// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

const int INF = 500000;

int n, m;
vector<int> G[200000];

int dijkstra() {
  vector<int> dp(200000, INF);
  vector<bool> done(200000, false);
  priority_queue<pair<int, int> > Q;
  Q.push({0, 0});
  dp[0] = 0;
  
  while (Q.size()) {
    auto p = Q.top(); Q.pop();
    int v = p.second;
    if (done[v]) continue;
    done[v] = true;
    for (auto u: G[v]) {
      if (dp[v] + 1 >= dp[u]) continue;
      dp[u] = dp[v] + 1;
      Q.push({dp[u] , u});
    }
  }
  
  return dp[n-1];
}

int main() {
  cin >> n >> m;
  loop(i,0,m) {
    int a, b;
    cin >> a >> b; a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  if (dijkstra() <= 2) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}
