#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second
#define lwb lower_bound
#define upb upper_bound
#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in", "r", stdin);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i, --i;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (a[a[i]] == i);
  }
  cout << ans / 2 << '\n';
}
