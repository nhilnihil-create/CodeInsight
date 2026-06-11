#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  ll a[7];
  rep(i,7) cin >> a[i];
  ll ans = a[1];
  bool can = (a[0] % 2 && a[3] % 2 && !(a[4] % 2) && a[4] > 0) || (a[0] % 2 && !(a[3] % 2) && a[4] % 2 && a[3] > 0) || (!(a[0] % 2) && a[3] % 2 && a[4] % 2 && a[0] > 0) || (a[0] % 2 && a[3] % 2 && a[4] % 2);
  if(can) {
    ans += 3;
    a[0]--; a[3]--; a[4]--;
  }
  ans += a[0]/2*2 + a[3]/2*2 + a[4]/2*2;
  cout << ans << endl;
  return 0;
}