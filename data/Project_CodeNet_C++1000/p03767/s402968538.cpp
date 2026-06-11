#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(3*n);
  rep(i, 3*n) cin >> a[i];
  sort(a.begin(), a.end(), greater<int>());
  ll ans = 0;
  rep(i, 2*n) if (i % 2 == 1) ans += a[i];
  cout << ans << endl;
  return 0;
}