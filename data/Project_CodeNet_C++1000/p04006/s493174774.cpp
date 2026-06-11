#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <random>
#include <tuple>
#include <iomanip>
#include <cstring>

using namespace std;

typedef long long ll;
//typedef pair<int,int> Pint;
//typedef pair<ll, ll> P;
//typedef pair<ll, pair<ll, ll>> P;
//typedef tuple<int,int,int> T;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n-1); i >= 0; i--)
#define pb push_back
#define f first
#define s second
//const ll INFL = 1LL << 60;//10^18 = 2^60
const ll INFL = 1LL << 60;
const int INF = 1 << 30;//10^9
ll MOD = 1e9 + 7;
//ll MOD  = 998244353;
vector<ll> dy = {0, 0, 1, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, -1, 0, 0, 1, -1, 1, -1, 0};

ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}
ll pow_long(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x;
    k /= 2;
  }
  return res;
}
ll pow_mod(ll x, ll k){
  x %= MOD; x += MOD; x %= MOD;
  ll res = 1;
  while(k > 0){
    if(k % 2){
      res *= x; res %= MOD;
    }
    x *= x; x %= MOD;
    k /= 2;
  }
  return res;
}
ll inverse(ll x){return pow_mod(x, MOD - 2);};

//最大公約数
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

//最小公倍数
ll lcm(ll x, ll y){return x / gcd(x, y) * y;};

//コンビネーション
const int MAXcomb = 200010;
ll fac[MAXcomb], finv[MAXcomb], inv[MAXcomb];
//facはn!,finvは1/n!
//invは逆元
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAXcomb; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
ll comb(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * finv[k] % MOD * finv[n-k] % MOD;
}

const ll N_ = (1 << 18);
ll seg[2*N_-1];
//Range Minimum Query
void update(ll k, ll x){
  k += N_-1;
  seg[k] = x;
  while(k > 0){
    k = (k-1)/2;
    seg[k] = min(seg[2*k+1], seg[2*k+2]);
  }
}

ll query(ll x, ll y, ll k, ll left, ll right){
  if(right <= x || y <= left) return INFL;
  if(x <= left && right <= y) return seg[k];
  ll mid = (left + right) / 2;
  ll l = query(x, y, 2*k+1, left, mid);
  ll r = query(x, y, 2*k+2, mid, right);
  return min(l, r);
}

void init_seg(){
  rep(i, 2*N_-1) seg[i] = INFL;
}

int main(void){
  init_seg();
  ll N, x; cin >> N >> x;
  vector<ll> A(N); rep(i, N) cin >> A[i];
  rep(i, N) update(i, A[i]);
  ll ans = INFL;
  for(int i = 0; i < N; i++){
    ll res = x * i;
    for(int j = 0; j < N; j++){
      if(j >= i){
        res += query(j-i, j+1, 0, 0, N_);
      }else{
        res += min(query(0, j+1, 0, 0, N_), query(N+j-i, N, 0, 0, N_));
      }
    }
    ans = min(ans, res);
  }
  cout << ans << endl;
}
