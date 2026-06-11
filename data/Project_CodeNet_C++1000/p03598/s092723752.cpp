#include <bits/stdc++.h>

using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void milkshake() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ans += min(x-0, k-x)*2;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt=1;
  //cin >> tt;
  while(tt--) milkshake();

  return 0;
}
