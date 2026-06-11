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

  int n, c, k;
  cin >> n >> c >> k;
  vector<int> t(n);
  rep(i, 0, n) cin >> t[i];
  sort(t.begin(), t.end());

  int first = t[0], count = 1, ans = 1;
  rep(i, 1, n) {
    if (t[i] - first > k || count == c) {
      first = t[i];
      ans++;
      count = 1;
    } else {
      count++;
    }
  }

  cout << ans << endl;
}
