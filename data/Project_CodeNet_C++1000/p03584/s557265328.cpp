#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n, k;std::cin >> n >> k;
  vvl a = vv(n, 2, 0, ll);
  re(i, n) std::cin >> a[i][0] >> a[i][1];

  ll m = 0;
  ll ans = 0;

  ll o = 0;
  for(int i=0;i<n;i++){
    if(((o|a[i][0])&(~k))==0) ans+=a[i][1], o|=a[i][0];
  }
  for(int i=30;i>=0;i--){
    if((k&(1<<i))==0) continue;
    m += (1<<i);
    ll tmp = m-1;
    //std::cout << "now" << i << " " << tmp << '\n';
    ll buy = 0, v = 0;
    for(int j=0;j<n;j++){
      if((((buy|a[j][0])&(~tmp))==0)) buy |= a[j][0], v += a[j][1];
    }
    //std::cout << ans << '\n';
    ans = max(ans, v);
  }
  std::cout << ans << '\n';
  return 0;
}
