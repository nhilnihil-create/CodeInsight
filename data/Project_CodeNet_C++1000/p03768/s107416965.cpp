#include<array>
#include<iostream>
#include<utility>
#include<vector>
int main(){
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n);
  while(m--){
    int a, b;
    std::cin >> a >> b;
    --a;
    --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  struct node{
    int time, color;
    node(int x, int y) : time(x), color(y) {}
    void set(const node& x){if(x.time < time) *this = x;}
  };
  std::array<std::vector<std::pair<int, node>>, 11> qs;
  int q;
  std::cin >> q;
  std::vector<node> dp(n, node(q, 0)), prev = dp;
  while(q--){
    int v, d, c;
    std::cin >> v >> d >> c;
    qs[d].emplace_back(v - 1, node(q, c));
  }
  for(int d = 11; d--;){
    std::swap(dp, prev);
    for(int v = 0; v != n; ++v){
      dp[v] = prev[v];
      for(const int e : g[v]) dp[v].set(prev[e]);
    }
    for(const auto &e : qs[d]) dp[e.first].set(e.second);
  }
  for(const auto &e : dp) std::cout << e.color << std::endl;
  return 0;
}
