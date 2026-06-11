#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int w, h, n;
  cin >> w >> h >> n;

  vector<int> x(n);
  vector<int> y(n);
  vector<int> a(n);
  rep(i, n) cin >> x.at(i) >> y.at(i) >> a.at(i);

  vector<vector<int>> square(w, vector<int>(h));
  rep(i, n) {
    if (a.at(i) == 1) {
      rep (j, w) {
        rep(k, h) {
          if (j < x.at(i)) {
            square.at(j).at(k) = 1;
          }
        }
      }
    } else if (a.at(i) == 2) {
      rep (j, w) {
        rep(k, h) {
          if (j >= x.at(i)) {
            square.at(j).at(k) = 1;
          }
        }
      }
    } else if (a.at(i) == 3) {
      rep (j, w) {
        rep(k, h) {
          if (k < y.at(i)) {
            square.at(j).at(k) = 1;
          }
        }
      }
    } else {
      rep (j, w) {
        rep(k, h) {
          if (k >= y.at(i)) {
            square.at(j).at(k) = 1;
          }
        }
      }
    }
  }

  int ans = 0;
  rep (i, w) {
    rep(j, h) {
      if (square.at(i).at(j) == 0) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}