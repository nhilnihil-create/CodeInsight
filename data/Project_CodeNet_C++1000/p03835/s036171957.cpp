#include <bits/stdc++.h>
using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  int n, x;
  cin >> n >> x;

  int count = 0;
  for(int i = 0; i <= n; ++i)
    for(int j = 0; j <= n; ++j) {
      int k = x - i - j;
      if(k >= 0 &&  k <= n) count++;
    }
  cout << count << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt=1;
  //cin >> T;
  while(tt--) solve();

  return 0;
}
