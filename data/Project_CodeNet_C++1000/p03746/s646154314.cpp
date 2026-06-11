#include<iostream>
#include<deque>
#include<vector>

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N, M; std::cin >> N >> M;
  std::vector<std::vector<int>> G(N);
  for(int i = 0; i < M; ++i) {
    int A, B; std::cin >> A >> B; --A; --B;
    G[A].push_back(B);
    G[B].push_back(A);
  }
  int a = 0, b = G[a][0];
  std::deque<int> ans = {a, b};
  std::vector<bool> used(N, false);
  used[a] = used[b] = true;
  for(;;) {
    bool ok = true;
    for(int v: G[ans.front()]) if(!used[v]) {
      ok = false;
      ans.push_front(v);
      used[v] = true;
      break;
    }
    if(!ok) continue;
    for(int v: G[ans.back()]) if(!used[v]) {
      ok = false;
      ans.push_back(v);
      used[v] = true;
      break;
    }
    if(ok) break;
  }
  std::cout << ans.size() << "\n";
  for(int i = 0; i < ans.size()-1; ++i) std::cout << (ans[i]+1) << " ";
  std::cout << ans.back()+1 << std::endl;
  return 0;
}