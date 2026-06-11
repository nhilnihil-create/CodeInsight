// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

typedef pair<int, int> Edge;

int n;
vector<Edge> G[100000];
vector<ll> D(100000, 0);

void dfs(int v, int p = -1, ll dist = 0) {
  D[v] = dist;
  for (auto &&edge: G[v]) {
    if (p == edge.first) continue;
    dfs(edge.first, v, dist + edge.second);
  }
}


int main() {
  cin >> n;
  loop(i,0,n-1) {
    int a, b, c; cin >> a >> b >> c;
    a--;b--;
    G[a].emplace_back(b, c);
    G[b].emplace_back(a, c);
  }
  int q, k; cin >> q >> k; k--;
  dfs(k);
  
  while (q--) {
    int x, y; cin >> x >> y; x--;y--;
    cout << D[x] + D[y] << endl;
  }
  
  return 0;
}
