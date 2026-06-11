#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  const int INF = 1000000007;
  vector<vector<int>> G(N, vector<int>(N, INF));
  for (int i = 0; i < N; i++) G.at(i).at(i) = 0;
  vector<int> A(M), B(M), C(M);
  for (int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    G.at(a).at(b) = c;
    G.at(b).at(a) = c;
    A.at(i) = a;
    B.at(i) = b;
    C.at(i) = c;
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        G.at(i).at(j) = min(G.at(i).at(j), G.at(i).at(k) + G.at(k).at(j));
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < M; i++) {
    bool ok = true;
    for (int s = 0; s < N; s++) {
      for (int t = 0; t < N; t++) {
        if (s == t) continue;
        if (G.at(s).at(t) == G.at(s).at(A.at(i)) + C.at(i) + G.at(B.at(i)).at(t)) {
          ok = false;
        }
      }
    }
    if (ok) ans++;
  }
  cout << ans << endl;
}