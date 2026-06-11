#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int mp[105][105];

int main() {
  int w, h, n;  // w -> x ,h -> y
  cin >> w >> h >> n;
  rep(i, h) {
    rep(j, w) { mp[i][j] = 1; }
  }

  rep(k, n) {
    int x, y, a;
    cin >> x >> y >> a;

    if (a == 1) {
      rep(i, h) {
        rep(j, x) {
          mp[i][j] = 0;
          // cout << "a";
        }
      }
    } else if (a == 2) {
      rep(i, h) {
        for (int j = x; j < w; j++) {
          mp[i][j] = 0;
          // cout << "b";
        }
      }
    } else if (a == 3) {
      rep(i, y) {
        rep(j, w) {
          mp[i][j] = 0;
          // cout << "c";
        }
      }
    } else {
      for (int i = y; i < h; i++) {
        rep(j, w) {
          mp[i][j] = 0;
          // cout << " d";
        }
      }
    }
  }

  int ans = w * h;
  rep(i, h) {
    rep(j, w) {
      if (!mp[i][j]) ans--;
    }
  }

  cout << ans;
  return 0;
}
