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

ll gcd(ll a, ll b){
  if(b<a) swap(a, b);
  ll r = a % b;
  if(r==0) return b;
  while(r!=0) r = a % b, a = b, b = r;
  return a;
}
ll lcm(ll a, ll b){return (a*b)/gcd(a, b);}
vll extgcd(ll a, ll b) {
  ll x, y;
  for (ll u = y = 1, v = x = 0; a;) {
    ll q = b / a;
    swap(x -= q * u, u);
    swap(y -= q * v, v);
    swap(b -= q * a, a);
  }
  return vll{x, y, b};
}
int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  ll s = 0;
  vll a(n);
  re(i, n){
    scanf("%lld", &a[i]);
    s += a[i] - 1;
  }
  if(n==1){
    std::cout << (a[0]==1?"Second":"First") << '\n';
    return 0;
  }
  if(s%2==1){
    std::cout << "First" << '\n';
    return 0;
  }

  ll tm = 0;
  while(true){
    ll idx = -1;
    bool flag = true;
    for(int i=0;i<n;i++){
      if(a[i]%2==1) {
        if(idx!=-1||a[i]==1){
          flag = false;
          break;
        }
        idx = i;
      }
    }
    if(!flag) break;
    a[idx]--;
    ll g = a[0];

    for(int i=1;i<n;i++) g = gcd(g, a[i]);
    ll p = 0;
    for(int i=0;i<n;i++) p += (a[i] - 1);
    ll t = 0;
    for(int i=0;i<n;i++){
      a[i]/=g;
      t += a[i] - 1;
    }
    if(p%2==t%2) break;
    tm++;
  }
  //std::cout << tm << '\n';
  std::cout << (tm%2?"First":"Second") << '\n';
  return 0;
}
