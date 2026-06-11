#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int idx = 0;
  vector<vector<int> > grid(h, vector<int>(w));
  rep(i, h) {
    if (i%2) {
      for (int j = w-1; j >= 0; j--) {
        grid[i][j] = idx+1;
        a[idx]--;
        if (!a[idx])
          idx++;
      }
    } else {
      rep(j, w) {
        grid[i][j] = idx+1;
        a[idx]--;
        if (!a[idx])
          idx++;
      }
    }
  }
  rep(i, h) rep(j, w)
    printf("%d%c", grid[i][j], j<w-1?' ':'\n');
  return 0;
}