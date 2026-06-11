//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
#define endn "\n"
typedef pair<int,int> P;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const int MOD = 1000000007;
//const int MOD = 998244353;
template<class T, class U> inline int add(T& a, U bb, T M = MOD){T b = bb;a=(a+M)%M;b=(b+M)%M;a=(a+b)%M;return a;};
template<class T, class U> inline int mul(T& a, U bb, T M = MOD){T b = bb;if(a>=M)a%=M;if(b>=M)b%=M;a*=b;if(a>=M)a%=M;return a;};
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
const string abc="abcdefghijklmnopqrstuvwxyz";
const string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

////////////////////////////////////////////////////////////////////
///////////////////////___modpow___////////////////////
ll modpow(ll a,  ll n, const ll &MOD = MOD){
  ll ret = n == 0 ? 1 : modpow(a, n/2, MOD);
  (ret *= ret);
  if(n%2)((ret *= a));
  return ret;
}
///////////////////////___modinv___////////////////////
ll modinv(ll d, const ll &MOD = MOD){
  return modpow(d, MOD-2, MOD);
}

vector<ll> fac, finv, inv;
void COMinit(const int MAX = 5000000, const ll &MOD = MOD){
  fac.resize(MAX);finv.resize(MAX);inv.resize(MAX);
  fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
  repd(i,2,MAX){
    fac[i] = fac[i-1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}
ll COM(int n, int k){
  if(n < k)return 0;
  if(n < 0 || k < 0)return 0;
  return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

template<typename T>
struct edge {
  int to, from;T cost;
  edge(int to) : from(-1), to(to), cost(-1) {}
  edge(int to, T cost) : from(-1), to(to), cost(cost) {}
  edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};
template<typename T>
using edges = vector<edge<T>>;
template<typename T>
using graph = vector<edges<T>>;
template<typename T>
using matrix = vector<vector<T>>;

template<typename T>
bool compByCost(const edge<T>& left, const edge<T>& right){
  return left.cost < right.cost; 
}
template<typename T>
vector<T> bellman(int s, graph<T> &g){
  vector<T> dist(g.size()+1, INF);dist[s] = 0;dist[g.size()] = 0;
  rep(cnt,g.size()){
    bool update = false;
    rep(i,g.size()){
      edges<T> es = g[i];
      rep(j,es.size()){
        edge<T> e = es[j];
        if(dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost){
          dist[e.to] = dist[e.from] + e.cost;
          update = true;
        }
      }
    }
    if(!update)break;
    if(cnt == g.size()-1){
      dist[g.size()] = 1;
      break;
    }
  }
  return dist;
}

#define bellman bellman<int>// edgeの初期化にfromが必要
class union_find{
  int N;vector<int> par;
  public:
    union_find(int n){
      N = n;
      par.resize(N);
      rep(i,N)par[i] = -1;
    }
    int find(int x){
      if(par[x] < 0)return x;
      else{
        return par[x] = find(par[x]);
      }
    }
    void unite(int x, int y){
      x = find(x);
      y = find(y);
      if(x == y)return;
      par[y] += par[x];
      par[x] = y;
    }
    bool same(int x, int y){
      return find(x) == find(y);
    }
    int size(int x){
      return -par[find(x)];
    }
};

////////////////////////////////////////////////////////////////////

int n,k,a[110000], g, m, x;
bool b;
signed main(){
  cin>>n>>k;m = INF;
  rep(i,n){
    cin>>a[i];
    g = __gcd(g, a[i]);
    chmin(m, a[i]);
    chmax(x, a[i]);
  }
  if(m <= k && k <= x && k % g == 0)b = true;
  cout << (b ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}

