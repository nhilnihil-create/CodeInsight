#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  ll q, h, s, d;
  cin >> q >> h >> s >> d;
  ll n;
  cin >> n;
  ll dq = q*8, dh = h*4, ds = s*2;
  ll mn = min({dq, dh, ds, d});
  ll ans = (n/2)*mn;
  n %= 2;
  dq = q*4, dh = h*2;
  mn = min({dq, dh, s});
  ans += n*mn;
  cout << ans << endl;
  return 0;
}