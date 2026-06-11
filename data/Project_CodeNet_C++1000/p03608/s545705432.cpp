#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> r(R);
  for (int i = 0; i < R; i++) {
    cin >> r.at(i);
    r.at(i)--;
  }

  vector<vector<int>> G(N, vector<int>(N, 1e9));
  for (int a, b, c; cin >> a >> b >> c;) {
    G.at(--a).at(--b) = c;
    G.at(b).at(a) = c;
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

  int ans = 1e9;
  sort(r.begin(), r.end());
  do {
    int tmp = 0;
    for (int i = 0; i + 1 < R; i++) {
      tmp += G.at(r.at(i)).at(r.at(i + 1));
    }
    ans = min(ans, tmp);
  } while (next_permutation(r.begin(), r.end()));
  cout << ans << "\n";
}