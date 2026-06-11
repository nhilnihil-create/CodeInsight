#include<iostream>
#include<vector>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<std::vector<int>> G(N);
  for(int i = 0; i < N-1; ++i) {
    int x, y; std::cin >> x >> y; --x; --y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  auto dfs = [&](auto&& f, int v, int p)->int {
    int res = 0;
    for(int c: G[v])if(c != p) res ^= f(f, c, v);
    return res+1;
  };
  int ans = dfs(dfs, 0, -1);
  fin(ans==1? "Bob": "Alice");
  return 0;
}
