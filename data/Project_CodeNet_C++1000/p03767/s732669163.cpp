#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  n *= 3;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(all(a));
  int ans = 0;
  for (int i = n - 2; i >= n - n / 3 * 2; i -= 2) {
    ans += a[i];
  }
  cout << ans << '\n';
}
