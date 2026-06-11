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
  for (int i = 1; i < N - 1; i++) {
    int a = 0, b = 0;
    for (auto g : G.at(i)) {
      if (g == 0) a++;
      if (g == N - 1) b++;
    }
    if (a && b) return cout << "POSSIBLE" << "\n", 0;
  }
  cout << "IMPOSSIBLE" << "\n";
}