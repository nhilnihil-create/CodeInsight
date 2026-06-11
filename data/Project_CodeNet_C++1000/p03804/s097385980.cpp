#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using GraphC = vector<vector<char>>;
using pint = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  GraphC A(N, vector<char>(N));
  rep(i, 0, N) rep(j, 0, N) cin >> A[i][j];
  GraphC B(M, vector<char>(M));
  rep(i, 0, M) rep(j, 0, M) cin >> B[i][j];

  rep(ly, 0, N) {
    rep(lx, 0, N) {
      // 範囲外
      if (ly + M - 1 >= N || lx + M - 1 >= N) continue;

      bool match = true;
      rep(y, 0, M) {
        rep(x, 0, M) {
          if (A[ly + y][lx + x] != B[y][x]) {
            match = false;
            break;
          }
        }
      }
      if (match) {
        cout << "Yes" << endl;
        return 0;
      };
    }
  }

  cout << "No" << endl;
  return 0;
}
