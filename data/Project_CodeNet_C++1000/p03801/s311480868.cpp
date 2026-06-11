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
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n-1); i >= 0; i--)
#define pb push_back
#define f first
#define s second
ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}
ll max3(ll a, ll b, ll c){return max(a, max(b, c));};
ll min3(ll a, ll b, ll c){return min(a, min(b, c));};
ll max4(ll a, ll b, ll c, ll d){return max(max(a, b), min(c, d));};
ll min4(ll a, ll b, ll c, ll d){return min(min(a, b), min(c, d));};
ll max5(ll a, ll b, ll c, ll d, ll e){return max(max(a, b), max3(c, d, e));};
ll min5(ll a, ll b, ll c, ll d, ll e){return min(min(a, b), min3(c, d, e));};

const ll INFL = 1LL << 60;//10^18 = 2^60
const int INF = 1 << 30;//10^9
ll MOD = 1000000007;
vector<ll> dy = {0, 0, 1, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, -1, 0, 0, 1, -1, 1, -1, 0};

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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll x, ll y){return x / gcd(x, y) * y;};

ll kai_mod(ll x){
  if(x == 0) return 1;
  return x * kai_mod(x-1) % MOD;
}

/*
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
*/

ll N_ = 1;
ll seg[(1 << 20) - 1], lazy[(1 << 20) - 1];

void eval(ll k, ll l, ll r){
  if(lazy[k] == 0) return;
  seg[k] += lazy[k];
  if(r - l > 1){
    lazy[2 * k + 1] += lazy[k] / 2;
    lazy[2 * k + 2] += lazy[k] / 2;
  }
  lazy[k] = 0;
}

void add(ll a, ll b, ll x, ll k, ll l, ll r){
  eval(k, l, r);
  if(r <= a || b <= l) return;
  if(a <= l && r <= b){
    lazy[k] += (r - l) * x;
    eval(k, l, r);
    return;
  }
  add(a, b, x, 2 * k + 1, l, (l + r) / 2);
  add(a, b, x, 2 * k + 2, (l + r) / 2, r);
  seg[k] = seg[2 * k + 1] + seg[2 * k + 2];
  return;
}

ll sum(ll a, ll b, ll k, ll l, ll r){
  if(b <= a) return 0;
  if(r <= a || b <= l) return 0;
  eval(k, l, r);
  if(a <= l && r <= b) return seg[k];
  ll suml = sum(a, b, 2 * k + 1, l, (l + r) / 2);
  ll sumr = sum(a, b, 2 * k + 2, (l + r) / 2, r);
  return suml + sumr;
}


int main(){
  ll N;
  cin >> N;
  while(N_ < N) N_ *= 2;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  vector<ll> xs;
  xs.pb(INFL);
  rep(i, N) xs.pb(A[i]);
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());

  rep(i, N){
    ll at = lower_bound(xs.begin(), xs.end(), A[i]) - xs.begin();
    add(0, at + 1, 1, 0, 0, N_);
  }

  ll M = 0;
  ll used = 0;
  rep(i, N){
    if(A[i] <= M){
      cout << 0 << endl;
    }else{
      ll res = 0;
      while(xs[used] <= A[i]){
        if(used == 0) res += sum(used, used + 1, 0, 0, N_) * xs[used];
        else res += sum(used, used + 1, 0, 0, N_) * (xs[used] - xs[used-1]);
        used++;
      }
      cout << res << endl;
      M = A[i];
    }
  }
}
