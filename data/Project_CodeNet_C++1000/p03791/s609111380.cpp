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

//-------------------------------------------------------------------
#define P 1000000007
#define N_MAX 2000000
typedef long long int ll;
ll fac[N_MAX+1];
ll inv[N_MAX+1];
ll finv[N_MAX+1];

ll comb(ll n, ll k){
    return (((fac[n]*finv[n-k])%P)*finv[k])%P;
}

void init(){
    fac[0] = finv[0] = fac[1] = finv[1] = inv[1] = 1;
    for(int i = 2; i <= N_MAX; i++){
        fac[i] = (fac[i-1]*i)%P;
        inv[i] = ((-(P/i)*inv[P%i])%P+P)%P;
        finv[i] = (finv[i-1]*inv[i])%P;
    }
}
ll pp(ll a, ll b){
  return (a * b)%P;
}
//-------------------------------------------------------------------
int main(int argc, char const *argv[]) {
  ll ans = 1, n;std::cin >> n;
  vll x(n);re(i, n) std::cin >> x[i];
  init();
  ll now=0;
  re(i, n){
    while(now!=n-1){
      if((x[now]/2 + (x[now]%2==1?1:0))<now+1-i) break;
      now++;
    }
    //std::cout << now << '\n';
    ans = pp(ans, now+1 - i);
  }
  std::cout << ans << '\n';
  return 0;
}
