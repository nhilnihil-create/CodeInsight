#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N; string s, t;
  cin >> N >> s >> t;

  int ans = 0;
  rep(i,1,N) {
    string l = s.substr(N-i,i);
    string r = t.substr(0,i);
    if (l.compare(r) == 0) {
      ans = i + (N - i) * 2;
    }
  }

  if (ans == 0) ans = N * 2;
  cout << ans << endl;
  return 0;
}
