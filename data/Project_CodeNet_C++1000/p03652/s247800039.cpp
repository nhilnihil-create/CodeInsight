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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, n) rep(j, m) {
    cin >> a[i][m-1-j];
    a[i][m-1-j]--;
  }
  vector<int> num(m);
  rep(i, n) num[a[i].back()]++;
  int mx = 0, idx;
  rep(i, m) {
    if (chmax(mx, num[i]))
      idx = i;
  }
  vector<bool> exist(m, true);
  int ans = mx;
  rep(i, m-1) {
    num[idx] = 0;
    exist[idx] = false;
    rep(j, n) {
      if (!exist[a[j].back()]) {
        while (!exist[a[j].back()])
          a[j].pop_back();
        num[a[j].back()]++;
      }
    }
    mx = 0;
    rep(j, m) {
      if (chmax(mx, num[j]))
        idx = j;
    }
    chmin(ans, mx);
  }
  cout << ans << endl;
  return 0;
}