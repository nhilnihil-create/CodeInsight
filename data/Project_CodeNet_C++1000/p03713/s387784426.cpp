#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll h, w, m1 = 0, m2 = 0, m3 = 0, minm, maxm, mind = INF;
  cin >> h >> w;

  for (int i = 1; i < h; ++i) {
    m1 = i * w;

    int ww = ceil(w / 2.0);
    m2 = (h - i) * ww;
    m3 = h * w - m1 - m2;
    maxm = max({m1, m2, m3});
    minm = min({m1, m2, m3});
    mind = min(maxm - minm, mind);

    int hh = ceil((h - i) / 2.0);
    m2 = hh * w;
    m3 = h * w - m1 - m2;
    maxm = max({m1, m2, m3});
    minm = min({m1, m2, m3});
    mind = min(maxm - minm, mind);
  }

  swap(h, w);
  for (int i = 1; i < h; ++i) {
    m1 = i * w;

    int ww = ceil(w / 2.0);
    m2 = (h - i) * ww;
    m3 = h * w - m1 - m2;
    maxm = max({m1, m2, m3});
    minm = min({m1, m2, m3});
    mind = min(maxm - minm, mind);

    int hh = ceil((h - i) / 2.0);
    m2 = hh * w;
    m3 = h * w - m1 - m2;
    maxm = max({m1, m2, m3});
    minm = min({m1, m2, m3});
    mind = min(maxm - minm, mind);
  }

  cout << mind << endl;
  return 0;
}
