#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

const int N = 1e5;

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(N + 2);
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    a[t]++;
    a[t + 1]++;
    a[t + 2]++;
  }
  int ans = 0;
  for (int i = 0; i <= N + 1; i++) {
    ans = max(ans, a[i]);
  }
  cout << ans << '\n';
}
