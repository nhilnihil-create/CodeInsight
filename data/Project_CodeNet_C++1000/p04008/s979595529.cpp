#include<bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

class Tree {
 public:
  Tree(const auto& G) : N(G.size()), parent(G.size()), depth(G.size()), child(G.size()) {build(G);}
  int solve(auto K) {
    auto res = 0;
    vector<bool> used(N);
    priority_queue<pair<int, int>> q;
    for(auto v=0; v<N; ++v) if(child[v].empty()) q.emplace(depth[v], v);
    used[0] = true;
    while(!q.empty()) {
      int d, v;
      tie(d, v) = q.top();
      q.pop();
      if(used[v]) continue;
      used[v] = true;
      auto del = true;
      auto r = v;
      for(auto i=0; i<K-1; ++i) {
        r = parent[r];
        if(used[r]) {
          del = false;
          break;
        }
        used[r] = true;
      }
      if(used[parent[r]]) del = false;
      if(!del) continue;
      ++res;
      if(!used[parent[r]]) q.emplace(depth[parent[r]], parent[r]);
    }
    return res;
  }
 private:
  void build(const auto& G) {
    function<int(int, int)> dfs = [&](int cur, int pre) {
      parent[cur] = pre;
      depth[cur] = depth[pre] + 1;
      for(auto nex: G[cur]) if(nex != pre) child[cur].emplace_back(dfs(nex, cur));
      return cur;
    };
    dfs(0, 0);
  }
  int N;
  vector<int> parent, depth;
  vector<vector<int>> child;
};

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for(auto& i: A) cin >> i;

  int ans = 0;
  if(A[0] != 1) ++ans;
  Graph G(N);
  for(auto i=1; i<N; ++i) {
    auto u=i, v=A[i]-1;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  cout << ans + Tree(G).solve(K) << endl;
}
