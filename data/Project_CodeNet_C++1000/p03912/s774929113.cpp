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
  ll a, n, m;std::cin >> n >> m;
  vll dat(m, 0), p(m, 0);

  map<ll, ll> mp;
  re(i, n){
    std::cin >> a;
    dat[a%m]++;
    if(mp.find(a)==mp.end()) mp.emplace(a, 1);
    else (*mp.find(a)).second++;
  }
  for(auto itr = mp.begin();itr!=mp.end();itr++){
    ll num = (*itr).first, k = (*itr).second;
    p[num%m]+=k/2;
  }
  ll ans = 0;
  for(int i=1;i<m/2+(m%2==1?1:0);i++){
    ll k = min(dat[i], dat[m-i]);
    ll a = k + min((dat[i]-k)/2, p[i]) + min((dat[m-i]-k)/2, p[m-i]);
    ll b = 0;
    if(k>0){
      k--;
      b = k + min((dat[i]-k)/2, p[i]) + min((dat[m-i]-k)/2, p[m-i]);
    }
    ans += max(a, b);
  }
  ans += dat[0]/2;
  if(m%2==0) ans += dat[m/2]/2;
  std::cout << ans << '\n';
  return 0;
}
