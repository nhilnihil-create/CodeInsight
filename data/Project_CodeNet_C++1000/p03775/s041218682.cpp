#include <bits/stdc++.h>

using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void milkshake() {
  long long n;
  cin >> n;
  long long a;
  for(long long i = 1; i*i <= n; i++) {
    if(n % i != 0) continue;
    a = i;
  }
  long long b = n/a, ans = 0;
  while(b) {
    b /= 10;
    ans++;
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
