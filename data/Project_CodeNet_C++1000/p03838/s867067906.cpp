#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  ll x,y;
  cin >> x >> y;
  ll ans = INF;
  {
    if (x<=y) ans =min(ans,y-x);
  }
  {
    ll nx=-x; 
    if (nx<=y) ans=min(ans,y-nx+1);
  }
  {
    ll ny=-y;
    if(x<=ny) ans=min(ans,ny-x+1);
  }{
    ll nx=-x,ny=-y;
    if(nx<=ny) ans=min(ans,ny-nx+2);
  }
  cout << ans << endl;
  return 0;
}