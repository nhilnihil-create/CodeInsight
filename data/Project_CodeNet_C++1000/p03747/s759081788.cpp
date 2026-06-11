#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;


int main(int argc, char const *argv[]) {
  ll n, l, t;std::cin >> n >> l >> t;
  vvl dat = VV(n, 2, 0, ll);
  vll af(n);
  for(int i=0;i<n;i++) scanf("%lld %lld", &dat[i][0], &dat[i][1]);

  ll y;
  //最初にi番目にいたアリの位置
  for(int i=0;i<n;i++){
    ll x = t%l;
    if(dat[i][1]==1) af[i] = dat[i][0]+x;
    else af[i] = dat[i][0]-x+l;
    if(af[i]>=l) af[i]-=l;
    if(i==0) y = af[i];
  }
  sort(all(af));
  for(int i=0;i<n;i++){
    if(af[i]==y) {
      y = i;
      break;
    }
  }
  ll z = 0;
  //アリ0が終了後にアリ何番目になっているか
  ll num = 0;
  for(int i=1;i<n;i++){
    if(dat[i][1]==dat[0][1]) continue;
    //t秒間で2t進める
    ll fst = (dat[0][1]==1?(dat[i][0]-dat[0][0]):(l-(dat[i][0]-dat[0][0])));
    if(fst>2*t) continue;
    num++;
    num += (2*t-fst)/l;
    if((2*t-fst)%l==0) z++;
  }
  if(dat[0][1]==1) num -= z;
  num = (num%n==0?(num==0?0:n):num%n);
  ll after = (dat[0][1]==1?num:(n-num)%n);
  vll ans(n);
  for(int i=0;i<n;i++) ans[(after+i)%n] = af[(i+y)%n];
  for(int i=0;i<n;i++) std::cout << ans[i] << "\n";
  return 0;
}
