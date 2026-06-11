#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
//typedef pair<ll, ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n)-1; i >= 0; i--)
#define pb push_back
#define f first
#define s second
/*
ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}
ll max3(ll a, ll b, ll c){return max(a, max(b, c));};
ll min3(ll a, ll b, ll c){return min(a, min(b, c));};
ll max4(ll a, ll b, ll c, ll d){return max(max(a, b), min(c, d));};
ll min4(ll a, ll b, ll c, ll d){return min(min(a, b), min(c, d));};
ll max5(ll a, ll b, ll c, ll d, ll e){return max(max(a, b), max3(c, d, e));};
ll min5(ll a, ll b, ll c, ll d, ll e){return min(min(a, b), min3(c, d, e));};
*/
const ll INFL = 1LL << 60;//10^18 = 2^60
const int INF = 1 << 30;//10^9
//ll MOD = 1000000007;
ll MOD = 998244353;

vector<ll> dy = {0, 0, 1, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, -1, 0, 0, 1, -1, 1, -1, 0};

//デバッグ
void BinarySay(ll x, ll y = 60){rep(i, y) cout << (x>>(y-1-i) & 1); cout << endl;}

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

//約数の列挙O(√n)
vector<ll> divisor(ll n){
    vector<ll> res(0);
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n/i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

//素因数列挙
vector<ll> MakePrimeList(ll x) {
    vector<ll> res;
    for(ll k=2; k*k<=x; k++) {
        if(x % k == 0) {
            res.pb(k);
            while(x % k == 0) x /= k;
        }
    }
    if(x > 1) res.push_back(x);
    return res;
}


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

const ll N_ = 1<<20;
ll seg[2 * N_ - 1], lazy[2 * N_ - 1];

void eval(ll k, ll l, ll r){
  if(lazy[k] == 0) return;
  seg[k] += lazy[k];
  if(r - l > 1){
    lazy[2 * k + 1] += lazy[k] / 2;
    lazy[2 * k + 2] += lazy[k] / 2;
  }
  lazy[k] = 0;
}

void add(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = N_){
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

ll getsum(ll a, ll b, ll k = 0, ll l = 0, ll r = N_){
  if(r <= a || b <= l) return 0;
  eval(k, l, r);
  if(a <= l && r <= b) return seg[k];
  ll res = -1;
  ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
  ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
  return vl + vr;
}


int main(){
  ll N, M;
  cin >> N >> M;
  vector<ll> cnt(M+1, 0);
  vector<ll> E[M+1];
  rep(i, N){
    ll l, r;
    cin >> l >> r;
    cnt[r-l+1]++;
    E[r-l+1].pb(l);
  }
  rep(i, M){
    cnt[i+1] += cnt[i];
  }

  for(ll i = 1; i <= M; i++){
    ll ans = cnt[M] - cnt[i-1];
    for(ll j = i; j <= M; j+=i){
      ans += getsum(j, j+1);
    }
    cout << ans << endl;
    for(ll sta : E[i]){
      add(sta, sta + i, 1);
    }
  }

}
