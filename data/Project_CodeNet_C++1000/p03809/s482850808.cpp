#include<bits/stdc++.h>
using namespace std;
bool ok(auto& G, auto& A, auto cur, auto pre) {
  auto s = 0;
  auto m = -1;
  for(auto nex: G[cur]) if(nex != pre) {
    if(!ok(G, A, nex, cur)) return false;
    s += A[nex];
    m = max(m, A[nex]);
  }
  if(cur == pre) {
    if(G[cur].size() == 1) return A[cur] == s;
    return 2*A[cur] == s;
  }
  if(m == -1) return A[cur] <= A[pre];
  if(s < A[cur]) return false;
  A[cur] = 2*A[cur] - s;
  return s-A[cur] <= 2*min(s-m, s/2);
}
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(auto& i: A) cin >> i;
  vector<vector<int>> G(N);
  for(auto i=1; i<N; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  cout << (ok(G, A, 0, 0) ? "YES" : "NO") << endl;
}
