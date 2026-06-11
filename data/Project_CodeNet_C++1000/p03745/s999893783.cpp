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
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  int bef = a[0], direct = 0, ans = 1;

  rep(i, 1, n) {
    if (direct == 0) {
      if (a[i] > bef)
        direct = 1;
      else if (a[i] < bef)
        direct = 2;
    } else {
      if ((a[i] > bef && direct == 2) || (a[i] < bef && direct == 1)) {
        direct = 0;
        ans++;
      }
    }
    bef = a[i];
  }

  cout << ans << endl;
}
