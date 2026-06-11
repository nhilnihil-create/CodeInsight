#include <bits/stdc++.h>

using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void milkshake() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int x = a[0];
  for(int i = 1; i <= n; i++) {
    if(x == 2) drop(i);
    x = a[x-1];
  }
  cout << -1 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt=1;
  //cin >> tt;
  while(tt--) milkshake();

  return 0;
}
