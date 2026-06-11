#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll H; cin >> H;
  ll W; cin >> W;
  ll N; cin >> N;
  vector<ll> A(N); for (ll i = 0; i < N; i++) cin >> A[i];

  int dr[] = {0, 1, 0, -1};
  int dc[] = {1, 0, -1, 0};
  vector<vector<ll>> cells(H, vector<ll>(W, 0));
  int cnt = 0, r = 0, c = 0, d = 0, n = 1;
  while (true) {
    if (cells[r][c] == 0) {
      cells[r][c] = n;
      cnt++;
      if (cnt == A[n - 1]) {
        cnt = 0;
        n++;
        if (n > N) break;
      }
    }
    for (ll i = 0; i < 4; i++) {
      ll nr = r + dr[d], nc = c + dc[d];
      if (nr >= 0 && nr < H && nc >= 0 && nc < W) {
        if (cells[nr][nc] == 0) {
          r = nr, c = nc;
          break;
        }
      } {
        d++; d %= 4;
      }
    }
  }

  for (int i = 0; i < cells.size(); i++) { cout << cells[i][0]; for (int j = 1; j < cells[i].size(); j++) { cout << ' ' << cells[i][j]; } cout << '\n'; }
  return 0;
}