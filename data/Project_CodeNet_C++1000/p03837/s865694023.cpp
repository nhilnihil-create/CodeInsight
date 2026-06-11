#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(N, vector<int>(N, 1e9));
  vector<vector<int>> V(M, vector<int>(3));
  for (int i = 0, a, b, c; cin >> a >> b >> c; i++) {
    G.at(--a).at(--b) = c;
    G.at(b).at(a) = c;
    V.at(i).at(0) = a;
    V.at(i).at(1) = b;
    V.at(i).at(2) = c;
  }
  for (int i = 0; i < N; i++) {
    G.at(i).at(i) = 0;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        G.at(j).at(k) = min(G.at(j).at(k), G.at(j).at(i) + G.at(i).at(k));
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < M; i++) {
    int a = V.at(i).at(0);
    int b = V.at(i).at(1);
    int c = V.at(i).at(2);
    if (G.at(a).at(b) < c) cnt++;
  }
  cout << cnt << "\n";
}