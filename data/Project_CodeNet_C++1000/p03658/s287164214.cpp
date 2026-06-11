#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )
 
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N, K;
  cin >> N >> K;

  vector<int> l(N);
  REP(i, N) cin >> l[i];

  sort(l.begin(), l.end(), greater<int>());
  int ans = 0;
  REP(i, K) ans += l[i];

  cout << ans << endl;

  return 0;
}
