#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  vector<int> cnt(26, 0);
  rep(i, h) rep(j, w) cnt[a[i][j] - 'a']++;

  bool ok = true;
  if (h % 2 == 0 && w % 2 == 0) {
    rep(i, 26) if (cnt[i] % 4) ok = false;
  }
  if (h % 2 == 0 && w % 2 == 1) {
    int t = 0;
    rep(i, 26) {
      if (cnt[i] % 2) ok = false;
      else if (cnt[i] % 4) ++t;
    }
    if (2 * t > h) ok = false;
  }
  if (h % 2 == 1 && w % 2 == 0) {
    int t = 0;
    rep(i, 26) {
      if (cnt[i] % 2) ok = false;
      else if (cnt[i] % 4) ++t;
    }
    if (2 * t > w) ok = false;
  }
  if (h % 2 == 1 && w % 2 == 1) {
    int o = 0, t = 0;
    rep(i, 26) {
      if (cnt[i] % 2) ++o;
      else if (cnt[i] % 4) ++t;
    }
    if (o > 1) ok = false;
    if (2 * t > h + w - 2) ok = false;
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}