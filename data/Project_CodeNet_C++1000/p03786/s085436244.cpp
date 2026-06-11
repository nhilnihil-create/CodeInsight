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

  sort(a.begin(), a.end());
  vector<ll> cum(n);
  cum[0] = a[0];
  for (int i = 1; i < n; ++i) cum[i] = cum[i-1] + a[i];

  reverse(a.begin(), a.end());
  reverse(cum.begin(), cum.end());

  int ans = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i-1] > 2 * cum[i]) break;
    ++ans;
  }
  cout << ans << endl;
  return 0;
}