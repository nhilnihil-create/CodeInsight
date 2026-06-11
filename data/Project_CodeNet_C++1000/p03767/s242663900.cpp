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
  vector<int> a(3 * n);
  rep(i, 0, 3 * n) cin >> a[i];
  sort(a.begin(), a.end());

  int l = 0, r = 3 * n - 1;
  ll ans = 0;
  rep(i, 0, n) {
    ans += a[r - 1];
    l++;
    r -= 2;
    if (r <= l)
      break;
  }
  cout << ans << endl;
}
