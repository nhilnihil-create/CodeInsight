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
//#include <tuple>
#include <iomanip>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
//ll MOD = 998244353;
/*
vector<ll> dy = {0, 0, 1, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, -1, 0, 0, 1, -1, 1, -1, 0};
*/

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

ll N, K;
vector<ll> tree[100010];
vector<ll> depth(100010);
const ll MAX_LOG_N = 20;
ll parent[MAX_LOG_N][100010];
map<pair<ll, ll>, ll> memo;
ll ans;
set<ll> erased;
void erase_children(ll now, ll length){
  if(length == 0) return;
  erased.insert(now);
  for(ll to : tree[now]) erase_children(to, length - 1);
}


void make_depth(ll now, ll dep){
  depth[now] = dep;
  for(ll to : tree[now]){
    make_depth(to, dep + 1);
  }
}

void make_parent_board(){
  for(ll k = 0; k + 1 < MAX_LOG_N; k++){
    for(ll v = 0; v < N; v++){
      if(parent[k][v] < 0) parent[k+1][v] = -1;
      else parent[k+1][v] = parent[k][parent[k][v]];
    }
  }
}


int main(){
  cin >> N >> K;

  rep(i, N){
    ll a;
    cin >> a;
    a--;
    if(i == 0){
      if(a != 0) ans++;
      continue;
    }
    tree[a].pb(i);
    parent[0][i] = a;
  }
  make_depth(0, 0);
  make_parent_board();
  typedef pair<ll, ll> P;
  priority_queue<P> pque;
  //深さ、頂点番号
  rep(i, N){
    if(depth[i] > K){
      pque.push({depth[i], i});
    }
  }
  while(!pque.empty()){
    P p = pque.top();
    pque.pop();
    if(erased.count(p.s)) continue;
    ans++;
    ll now = p.s;
    ll rest = K-1;
    //rest回たどる
    for(ll k = 0; k < MAX_LOG_N; k++){
      if((rest >> k) & 1) now = parent[k][now];
    }
    erase_children(now, K);
  }
  cout << ans << endl;
}
