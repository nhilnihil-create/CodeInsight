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
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n)-1; i >= 0; i--)
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
//ll MOD = 998244353;

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

int main(){
  ll N;
  cin >> N;
  bool l = 1;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  sort(A.begin(), A.end());
  ll m = A[0], M = A[N-1];
  if(M % 2 == 0){
    if(m != M/2) l = 0;
    if(A[0] == A[1]) l = 0;
    for(ll i = m+1; i <= M; i++){
      ll cnt = 0;
      rep(j, N) if(A[j] == i) cnt++;
      if(cnt < 2) l = 0;
    }
  }else{
    if(m != M/2 + 1) l = 0;
    ll cnt2 = 0;
    rep(j, N) if(A[j] == m) cnt2++;
    if(cnt2 != 2) l = 0;
    for(ll i = m+1; i <= M; i++){
      ll cnt = 0;
      rep(j, N) if(A[j] == i) cnt++;
      if(cnt < 2) l = 0;
    }
  }
  if(l) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}
