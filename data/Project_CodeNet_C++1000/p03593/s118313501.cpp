#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int h, w;
  cin >> h >> w;
  V<string> g(h);
  rep(i, h) cin >> g[i];

  V<int> his;
  for (char c = 'a'; c <= 'z'; c++) {
    int cnt = 0;
    rep(i, h) rep(j, w) {
      if (g[i][j] == c) cnt++;
    }
    if (cnt > 0) his.push_back(cnt);
  }
  int n = his.size();

  int div4(0), div2(0), div1(0);
  rep(i, n) if (his[i] % 4 == 0) div4++;
  rep(i, n) if (his[i] % 4 != 0 && his[i] % 2 == 0) div2++;
  rep(i, n) if (his[i] % 2 != 0) div1++;

  bool ans = true;
  if (h % 2 == 0 && w % 2 == 0) {
    if (div1 > 0 || div2 > 0) ans = false;
  } else if ((h + w) % 2 != 0) {
    int lim = 0;
    if (h % 2 == 0) {
      lim = h / 2;
    } else {
      lim = w / 2;
    }
    if (div1 > 0) ans = false;
    if (div2 > lim) ans = false;
  } else {
    if (div1 != 1) ans = false;
    if (div2 > h / 2 + w / 2) ans = false;
  }

  cout << ((ans) ? "Yes" : "No") << endl;
}
