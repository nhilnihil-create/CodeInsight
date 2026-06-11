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
ll MOD = 1000000007;
//ll MOD = 998244353;

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

ll N, M;
vector<ll> X;
void solve(){
  vector<ll> E[100010];
  rep(i, N) E[X[i] % M].pb(X[i]);

  rep(t, M){
    sort(E[t].begin(), E[t].end());
    map<ll, ll> cnt;
    rep(i, E[t].size()){
      cnt[E[t][i]]++;
    }
    vector<ll> EX, EY;
    revrep(i, E[t].size()){
      if(i == 0 || (i != 0 && E[t][i-1] != E[t][i])){
        if(cnt[E[t][i]] % 2){
          EX.pb(E[t][i]);
        }else{
          EY.pb(E[t][i]);
        }
      }else{
        EY.pb(E[t][i]);
      }
    }
    sort(EX.begin(), EX.end());
    sort(EY.begin(), EY.end());
    E[t].resize(0);
    rep(i, EX.size()){
      E[t].pb(EX[i]);
    }
    rep(i, EY.size()){
      E[t].pb(EY[i]);
    }
  }
  ll ans = 0;
  ans += E[0].size() / 2;
  if(M % 2 == 0){
    ans += E[M/2].size() / 2;
  }
  for(ll i = 1; i <= (M-1) / 2; i++){
    ll a = i;
    ll b = M - i;
    ll al = E[a].size();
    ll bl = E[b].size();
    ans += min(al, bl);
    if(al < bl){
      for(ll j = al; j < bl - 1; j++){
        if(E[b][j] == E[b][j+1]){
          ans++;
          j++;
        }
      }
    }else{
      for(ll j = bl; j < al - 1; j++){
        if(E[a][j] == E[a][j+1]){
          ans++;
          j++;
        }
      }
    }
  }
  cout << ans << endl;
}

int main(){
  cin >> N >> M;
  X.resize(N);
  rep(i, N) cin >> X[i];
  solve();
}
