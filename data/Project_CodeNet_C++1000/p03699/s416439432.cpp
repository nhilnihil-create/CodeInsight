#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
const int INF = 1001001001;

int main() {
  int N;
  cin >> N;

  vector<int> s(N);
  rep(i,0,N-1) cin >> s[i];

  int ans = accumulate(s.begin(), s.end(), 0);
  if (ans % 10 == 0) {
    int p = INF;
    rep(i,0,N-1) {
      if (s[i] % 10 != 0) p = min(p,s[i]);
    }
    if (p == INF) ans = 0;
    else ans -= p;
  }

  cout << ans << endl;
  return 0;
}
