#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, x, n) for (int i = (x); i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e18;
template<typename T> void cmax(T &a, T b) { a = max(a, b); }
template<typename T> void cmin(T &a, T b) { a = min(a, b); }

signed main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<string> ans = {"SS", "SW", "WS", "WW"};

  rep(i, 4) {
    loop(idx, 1, n - 1) {
      if (s[idx] == 'o') {
        if (ans[i][idx] == 'S')
          ans[i] += ans[i][idx - 1];
        else
          ans[i] += ans[i][idx - 1] == 'S' ? "W" : "S";
      } else {
        if (ans[i][idx] == 'S')
          ans[i] += ans[i][idx - 1] == 'S' ? "W" : "S";
        else
          ans[i] += ans[i][idx - 1];
      }
    }
  }
  rep(i, 4) ans[i] += ans[i] + ans[i];

  rep(i, 4) {
    int flag = true;
    loop(idx, n, 2 * n) {
      if (s[idx - n] == 'o') {
        if (ans[i][idx] == 'S' && (ans[i][idx - 1] != ans[i][idx + 1])) flag = false;
        if (ans[i][idx] == 'W' && (ans[i][idx - 1] == ans[i][idx + 1])) flag = false;
      } else {
        if (ans[i][idx] == 'S' && (ans[i][idx - 1] == ans[i][idx + 1])) flag = false;
        if (ans[i][idx] == 'W' && (ans[i][idx - 1] != ans[i][idx + 1])) flag = false;
      }
    }
    if (flag) {
      loop(j, n, 2 * n) cout << ans[i][j];
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}
