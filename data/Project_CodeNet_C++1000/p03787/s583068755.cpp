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

const ll MAX_V = 1000010;

ll par[MAX_V];//
ll Rank[MAX_V];
ll child[MAX_V];

void init_UF(){
  for(ll i = 0; i < MAX_V; i++){
    par[i] = i;
    Rank[i] = 1;
    child[i] = 1;
  }
}

ll find(ll x){
  if(par[x] == x) return x;
  else{
    return par[x] = find(par[x]);
  }
}

bool same(ll x, ll y){
  return find(x) == find(y);
}

void unite(ll x, ll y){
  ll rx = find(x), ry = find(y);
  if(rx != ry){
    if(Rank[rx] >= Rank[ry]){
      par[ry] = rx;
      if(Rank[rx] == Rank[ry]) Rank[rx]++;
      child[rx] += child[ry];
    }else{
      par[rx] = ry;
      child[ry] += child[rx];
    }
  }
}

ll N, M;
vector<ll> E[100010];
vector<ll> col(100010);//二部グラフ検出のため
bool odd_cycle(ll now, ll from, ll color){
  if(col[now] != 0){
    if(col[now] == color){
      return false;
    }else{
      return true;
    }
  }else{
    col[now] = color;
    for(ll to : E[now]){
      if(odd_cycle(to, now, -color)) return true;
    }
    return false;
  }
}


int main(){
  init_UF();
  cin >> N >> M;
  rep(i, M){
    ll u, v;
    cin >> u >> v;
    u--, v--;
    E[u].pb(v);
    E[v].pb(u);
    unite(u, v);
  }

  set<ll> used;
  ll isolate = 0, odd = 0, rest = 0;
  ll isolate_sum = 0, odd_sum = 0, rest_sum = 0;
  rep(i, N){
    ll pa = find(i);
    if(used.count(pa)) continue;
    used.insert(pa);
    if(child[pa] == 1){
      isolate++;
      isolate_sum++;
    }else{
      if(odd_cycle(pa, -1, 1)){
        odd++;
        odd_sum += child[pa];
      }else{
        rest++;
        rest_sum += child[pa];
      }
    }
  }

  ll ans = 0;
  ans += isolate_sum * N;
  ans += odd_sum * isolate_sum;
  ans += odd * odd;
  ans += odd * rest;
  ans += rest_sum * isolate_sum;
  ans += rest * odd;
  ans += rest * rest * 2;
  cout << ans << endl;
}
