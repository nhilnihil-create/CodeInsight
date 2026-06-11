#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define DEBUG(x) cerr << #x << " = " << x << endl
signed main() {
  ios::sync_with_stdio(false);
  int N, M; cin >> N >> M;
  vector<int> X(N);
  REP(i, N) cin >> X[i];
  sort(X.begin(), X.end());
  vector<int> same(M, 0);
  for(int i = 0; i < N; ) {
    int c = 0;
    int j;
    for(j = i + 1; j < N && X[i] == X[j]; ++j) {
    }
    c = j - i;
    same[X[i] % M] += c / 2;
    // DEBUG(X[i]); DEBUG(c);
    i += c;
  }
  vector<int> mod(M, 0);
  REP(i, N) {
    mod[X[i] % M]++;
  }
  int ans = 0;
  REP(i, M) {
    int j = (M - i) % M;
    if(i > j) break;
    // cerr << "i=" << i << " j=" << j << " mod[" << i <<"]=" << mod[i] << " mod[" << j << "]=" << mod[j] << " same[" << i << "]=" << same[i] << " same[" << j << "]=" << same[j] << endl;
    if(i == j) {
      ans += mod[i] / 2;
    }
    else {
      int use = min(mod[i], mod[j]);
      // DEBUG(use);
      ans += use;
      ans += min(same[i], (mod[i] - use) / 2);
      ans += min(same[j], (mod[j] - use) / 2);
    }
    // DEBUG(ans);
  }
  cout << ans << endl;
}
