#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for (int i = 0, a, b; cin >> a >> b; i++) {
    G.at(--a).push_back(--b);
    G.at(b).push_back(a);
  }
  for (auto g : G) cout << g.size() << "\n";
}