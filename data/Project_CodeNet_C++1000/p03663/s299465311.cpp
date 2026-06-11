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
#include <iomanip>
#define vll vector<ll>
#define vvv vector<vvl>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvvl(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

char c;
vll detect(vll d, ll k, ll mode = -1){
  ll l = (mode==1?1:0), r = 10;
  ll tmp = 0;
  for(int i=0;i<d.size();i++) tmp*=10, tmp+=d[i];
  while(r-l>1){
    ll mid = (l+r)/2;
    ll now = tmp * 10 + mid;
    for(int i=0;i<k-d.size()-1;i++) now *= 10;
    now *= 10;
    std::cout << "? " << now << '\n' << flush;
    std::cin >> c;
    if(c=='Y') r = mid;
    else l = mid;
  }
  d.push_back(l);
  return d;
}

int main(int argc, char const *argv[]) {
  ll l = 1, r = 11;
  while(r-l>1){
    ll mid = (l+r)/2;
    ll tmp = 1;
    for(int i=0;i<mid-1;i++) tmp *= 10;
    std::cout << "? " << tmp << '\n' << flush;
    std::cin >> c;
    if(c=='Y') l = mid;
    else r = mid;
  }
  bool flag = false;
  if(l==10){
    l = 1, r = 11;
    while(r-l>1){
      ll mid = (l+r)/2;
      ll tmp = 1;
      for(int i=0;i<mid-1;i++) tmp *= 10;
      tmp -= 1;
      std::cout << "? " << tmp << '\n' << flush;
      std::cin >> c;
      if(c=='Y') r = mid;
      else l = mid;
    }
    flag = true;
  }
  vll d;
  for(int i=0;i<l;i++) d = detect(d, l, (i==0?1:-1));
  ll ans = 0;
  re(i, d.size()) ans = ans * 10 + d[i];
  std::cout << "! " << ans+(flag?0:1) << '\n' << flush;
  return 0;
}
