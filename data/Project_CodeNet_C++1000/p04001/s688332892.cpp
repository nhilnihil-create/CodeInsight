#include <bits/stdc++.h>

using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  string s;
  cin >> s;
  int n = (int)s.size();
  long long ans = 0;
  for(int bit = 0; bit < (1<<(n-1)); ++bit) {
    long long num = s[0] - '0';
    for(int i = 0; i < n-1; ++i) {
      if(bit & (1<<i)) {
        ans += num;
        num = 0;
      }
      num = num * 10 + (s[i+1] - '0');
    }
    ans += num;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt=1;
  //cin >> tt;
  while(tt--) solve();

  return 0;
}
