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
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    ans += min(abs(t - 0), abs(t - k)) * 2;
  }
  cout << ans << '\n';
}
