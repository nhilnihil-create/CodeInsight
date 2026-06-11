#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> xy(m);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    xy.at(i) = make_pair(x, y);
  }
  vector<int> cnt(n, 1);
  vector<bool> possible(n, false);
  possible.at(0) = true;
  rep(i, m) {
    int x = xy.at(i).first;
    int y = xy.at(i).second;
    cnt.at(x)--;
    cnt.at(y)++;
    if (possible.at(x)) {
      possible.at(y) = true;
    }
    if (cnt.at(x) == 0) {
      possible.at(x) = false;
    }
  }
  int res = 0;
  rep(i, n) {
    if (possible.at(i) > 0) {
      res++;
    }
  }
  cout << res << endl;
  return 0;
}
