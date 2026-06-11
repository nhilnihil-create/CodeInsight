#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N, vector<int>(N, 1e9));
  for (int a, b, c; cin >> a >> b >> c;) {
    G.at(--a).at(--b) = c;
    G.at(b).at(a) = c;
  }
  for (int i = 0; i < N; i++) {
    G.at(i).at(i) = 0;
  }
  auto G2 = G;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        G.at(j).at(k) = min(G.at(j).at(k), G.at(j).at(i) + G.at(i).at(k));
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      if (G2.at(i).at(j) == 1e9) continue;
      if (G2.at(i).at(j) != G.at(i).at(j)) ans++;
    }
  }
  cout << ans / 2 << "\n";
}