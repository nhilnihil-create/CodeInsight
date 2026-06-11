#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  ll n,m;
  cin >> n >> m;
  ll ans = 0;
  ll p;
  p = min(n,ll(m/2));
  ans += p;
  n = n - p;
  m = m - 2*p;
  if(m < 4){
    cout << ans << endl;
    return 0;
  }
  ans += ll(m/4);
  cout << ans << endl;
  return 0;
}