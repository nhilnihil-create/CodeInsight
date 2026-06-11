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

const int MOD = 1e9+7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  vector<int> h(n);
  h[0] = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i-1])
      h[i] = a[i];
  }
  if (h.back() && h.back() != b.back()) {
    cout << 0 << endl;
    return 0;
  }
  h.back() = b.back();
  for (int i = n-2; i >= 0; i--) {
    if (h[i]) {
      if (b[i] != b[i+1] && h[i] != b[i]) {
        cout << 0 << endl;
        return 0;
      }
      if (b[i] == b[i+1] && h[i] > b[i]) {
        cout << 0 << endl;
        return 0;
      }
    }
    else if (b[i] != b[i+1])
      h[i] = b[i];
  }
  ll ans = 1;
  rep(i, n) {
    if (!h[i])
      (ans *= min(a[i-1], b[i+1])) %= MOD;
  }
  cout << ans << endl;
  return 0;
}