#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define RFOR(i,a,b) for(int i = (int)(b-1);i>=(int)(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

struct edge{
  int to;
  int cost;
};

void dfs(const vector<vector<edge>> &g, int v, int par, int dist, vector<int> &out){
  out[v] = dist;
  for(edge next_v : g[v]){
    if(next_v.to == par) continue;
    dfs(g, next_v.to, v, dist + next_v.cost, out);
  }
}

  
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  int n;
  cin >> n;

  vector<vector<edge>> g(n);
  REP(i, n - 1){
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  int q,k;
  cin >> q >> k;
  k--;
  vec x(q), y(q);
  REP(i, q){
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }

  vector<int> dist_to_k(n);
  dfs(g, k, -1, 0, dist_to_k);

  REP(i, q){
    cout << dist_to_k[x[i]] + dist_to_k[y[i]] << endl;
  }

  return 0;
}