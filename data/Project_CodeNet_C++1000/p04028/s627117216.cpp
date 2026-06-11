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

//-------------------------------------------------------------------
#define P 1000000007
#define N_MAX 2000000
ll fac[N_MAX+1], inv[N_MAX+1], finv[N_MAX+1];
ll comb(ll n, ll k){
  if(n<0||k<0||n<k) return 0;
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
ll mpow(ll a, ll b, ll p = -1){
  ll ret = 1, num = a;
  if(p==-1){
    while(b>0){
      if(b%2) ret *= num;
      num = num * num;
      b /= 2;
    }
  }else{
    while(b>0){
      if(b%2) ret = (ret*num)%p;
      num = (num*num)%p;
      b /= 2;
    }
  }
  return ret;
}
ll pp(ll a, ll b){
  return (a * b)%P;
}
ll n, m;
string s;
//-------------------------------------------------------------------
vvl dp;
ll dfs(ll ty, ll ok){
  if(ty==n) return (ok==m?1:0);
  if(dp[ty][ok]!=-1) return dp[ty][ok];
  ll ret = 0;
  // case back
  ret = (ret + dfs(ty+1, max((ll)0, ok-1)))%P;
  // case 0,1
  ret = (ret + dfs(ty+1, ok+1))%P;
  ret = (ret + dfs(ty+1, ok+1))%P;
  return dp[ty][ok] = ret;
}
int main(int argc, char const *argv[]) {
  std::cin >> n;
  std::cin >> s; m = s.size();
  init();
  ll d = mpow(inv[2], m, P);
  dp.resize(n+1, vll(n+1, -1));
  dfs(0, 0);
  std::cout << pp(dp[0][0], d) << '\n';
  return 0;
}
