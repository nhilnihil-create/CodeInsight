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
  ll n, P=1000000007, ans = 1;std::cin >> n;
  vll t(n), a(n);
  re(i, n) std::cin >> t[i];re(i, n) std::cin >> a[i];
  if(t[n-1]!=a[0]){
    std::cout << 0 << '\n';
    return 0;
  }
  bool flag = true;
  re(i, n){
    if((i==0||(t[i]!=t[i-1]))&&t[i]>a[i]) flag = false;
    if((i==0||(a[n-i-1]!=a[n-i]))&&a[n-i-1]>t[n-i-1]) flag = false;
  }
  if(!flag){
    std::cout << 0 << '\n';
    return 0;
  }
  re(i, n){
    if(!(i==0||(t[i]!=t[i-1]))&&!(i==n-1||(a[i]!=a[i+1]))){
      ans = (ans * min(a[i], t[i]))%P;
    }
  }
  std::cout << ans << '\n';
  return 0;
}
