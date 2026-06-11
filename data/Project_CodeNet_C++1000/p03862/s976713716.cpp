#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  if (a[0] > x) {
    ans += a[0] - x;
    a[0] = x;
  }
  for (int i = 1; i < n; ++i) {
    if (a[i-1] + a[i] > x) {
      ans += a[i-1] + a[i] - x;
      a[i] = x - a[i-1];
    }
  }
  cout << ans << endl;
  return 0;
}