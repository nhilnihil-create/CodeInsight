#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int m1 = 0;
  rep(i, n) if (a[i] % 2 == 1) ++m1;
  ll ans;
  if (m1 > 0) ans = pow(2LL, n-1);
  else if (p == 0) ans = pow(2LL, n);
  else ans = 0;
  cout << ans << endl;

  return 0;
}