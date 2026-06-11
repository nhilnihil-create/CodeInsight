#include<bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int dfs(const auto& G, auto cur, auto pre) {
  return accumulate(begin(G[cur]), end(G[cur]), 0, [&](auto g, auto to) {return to!=pre ? g^(dfs(G, to, cur)+1) : g;});
}

int main() {
  int N;
  cin >> N;
  Graph G(N);
  for(auto i = 1; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  if(dfs(G,0,0)) cout << "Alice" << endl;
  else           cout << "Bob" << endl;
}
