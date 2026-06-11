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
  int n, k;
  cin >> n >> k;
  int ans = k;
  for (int i = 2; i <= n; i++) {
    ans *= k - 1;
  }
  cout << ans << '\n';
}
