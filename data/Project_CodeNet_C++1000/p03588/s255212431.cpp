#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
  int n;
  cin >> n;

  vector<pair<int,int>> a(n);
  rep(i,n) cin >> a[i].first >> a[i].second;

  sort(a.begin(),a.end());
  int ans = a.back().first;
  int v = a.back().second;

  ans += v;

  cout << ans << '\n';

}

