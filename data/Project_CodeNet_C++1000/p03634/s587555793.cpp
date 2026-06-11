#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  vector<vector<pair<int, int>>> g(n);
  for(int i = 1; i < n; i++){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a--; b--;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  int q, k;
  scanf("%d %d", &q, &k);
  k--;
  vector<long> dist(n);
  auto dfs = [&](int from, int at, long d, const auto& dfs) -> void {
    dist[at] = d;
    for(auto i : g[at]) if(i.first != from){
      dfs(at, i.first, d + i.second, dfs);
    }
  };
  dfs(-1, k, 0, dfs);
  for(int i = 0; i < q; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    printf("%lld\n", dist[a] + dist[b]);
  }
}