#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  ll x = 1, y = 1;
  rep(i, 0, n) {
    ll t, a;
    cin >> t >> a;
    ll max_val = max((x + t - 1) / t, (y + a - 1) / a);
    x = max_val * t;
    y = max_val * a;
  }
  cout << x + y << endl;
}
