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

ll N, K;
vector<ll> E[2010];
ll dist[2010];
void dfs(ll now){
  for(ll to : E[now]){
    if(dist[to] == INFL){
      dist[to] = dist[now] + 1;
      dfs(to);
    }
  }
}

void solveEven(){
  ll ans = N;
  rep(i, N){
    rep(j, N) dist[j] = INFL;
    dist[i] = 0;
    dfs(i);
    ll sum = 0;
    rep(j, N){
      if(dist[j] <= K/2) sum++;
    }
    ans = min(ans, N-sum);
  }
  cout << ans << endl;
}

ll start[2010];
void dfs2(ll now, ll from, ll sta){
  start[now] = sta;
  for(ll to : E[now]){
    if(to == from) continue;
    dfs2(to, now, sta);
  }
}

void solveOdd(){
  ll ans = N;
  rep(i, N){
    rep(j, N) dist[j] = INFL;
    dist[i] = 0;
    dfs(i);
    ll sum = 0;
    rep(j, N){
      if(dist[j] <= K/2) sum++;
    }
    for(ll to : E[i]) dfs2(to, i, to);
    vector<ll> cnt(N);
    rep(j, N){
      if(dist[j] == (K+1) / 2) cnt[start[j]]++;
    }
    sort(cnt.begin(), cnt.end());
    sum += cnt.back();
    ans = min(ans, N-sum);
  }
  cout << ans << endl;
}

int main(){
  cin >> N >> K;
  rep(i, N-1){
    ll a, b;
    cin >> a >> b;
    a--, b--;
    E[a].pb(b);
    E[b].pb(a);
  }
  if(K % 2) solveOdd();
  else solveEven();
}
