#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int k, t;
  cin >> k >> t;
  vector<int> a(t);
  rep(i, t) cin >> a[i];

  sort(a.begin(), a.end(), greater<int>());
  int ans = max(0, 2 * a[0] - k - 1);
  cout << ans << endl;
  return 0;
}