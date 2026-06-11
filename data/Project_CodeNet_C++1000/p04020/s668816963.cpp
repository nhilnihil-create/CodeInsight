#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll ans = a[0] / 2;
  a[0] -= a[0] / 2 * 2;
  for (int i = 1; i < n; ++i) {
    if (a[i-1] == 1 && a[i] > 0) {
      a[i-1]--;
      a[i]--;
      ans++;
    }
    ans += a[i] / 2;
    a[i] -= a[i] / 2 * 2;
  }
  cout << ans << endl;
  return 0;
}