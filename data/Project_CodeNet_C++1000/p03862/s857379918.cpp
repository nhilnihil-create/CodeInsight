#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N, x;
  cin >> N >> x;

  vector<int> a(N);
  REP(i, N) cin >> a[i];

  int ans = max(0LL, a[0]-x);
  a[0] = min(a[0], x);
  for ( int i = 1; i < N; i++ ) {
    ans += max(0LL, a[i]-(x-a[i-1]));
    a[i] = min(a[i], x-a[i-1]);
  }

  cout << ans << endl;
  
  return 0;
}
