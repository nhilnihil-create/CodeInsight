#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int H, W, N;
  cin >> H >> W >> N;
  vi a(N);
  int ans[H][W];
  REP(i, N) cin >> a.at(i);
  int now = 0;

  REP(i, H) {
    if (i % 2 == 0) {
      REP(j, W) {
        ans[i][j] = now + 1;
        a.at(now)--;
        if (a.at(now) == 0) now++;
      }
    } else {
      for (int j = W - 1; j >= 0; j--) {
        ans[i][j] = now + 1;
        a.at(now)--;
        if (a.at(now) == 0) now++;
      }
    }
  }

  REP(i, H) {
    REP(j, W) cout << ans[i][j] << " ";
    cout << "\n";
  }

  return 0;
}