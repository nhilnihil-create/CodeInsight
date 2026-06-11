// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

/*
 * |n-m|>1 なら0.
 * |n-m|=0 ならn! * m! * 2
 * |n-m|=1 ならn! * m!
 */
const ll MOD = 1000000007;
int main() {
  ll n, m; cin >> n >> m;
  ll d = abs(n-m);
  if (d > 1) {
    cout << 0 << endl;
    return 0;
  }
  
  ll nBan = 1;
  loop(i,1,n+1) {
    nBan *= i;
    nBan %= MOD;
  }
  
  ll mBan = 1;
  loop(i,1,m+1) {
    mBan *= i;
    mBan %= MOD;
  }
  
  ll ans = (nBan * mBan) % MOD;
  if (d == 0) {
    ans = (ans * 2) % MOD;
  }
  
  cout << ans << endl;
  return 0;
}
