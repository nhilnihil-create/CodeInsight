#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define MOD (1000000007)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back

#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll keta(ll n){
  string s = to_string(n);
  ll num = s.size();
  return num;
}

const ll INF = 1LL << 60;

const int dh[4] = {1,0,-1,0};
const int dw[4] = {0,1,0,-1};

struct Edge{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w){}
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, int>;

void dfs(int v, vvi &G, vb &seen){
  if(seen[v]) return;
  seen[v] = true;
  for(auto nv : G[v]) {
    dfs(nv, G, seen);
  }
}

int main(){
  int n,m; cin >> n >> m;
  vector<tuple<int,int,ll>> edges;
  vvi G(n),rG(n);
  rep(i,m) {
    int a,b; ll c; cin >> a >> b >> c;
    a--; b--;
    c = -c;
    edges.emplace_back(a,b,c);
    G[a].pb(b);
    rG[b].pb(a);
  }

  vb seen1(n,false),seen2(n,false),ok(n);
  dfs(0, G, seen1);
  dfs(n-1, rG, seen2);
  rep(i,n) ok[i] = seen1[i]&seen2[i];

  vl d(n,INF);
  d[0] = 0;
  int step = 0;
  for(bool upd = true; upd; step++) {
    upd = false;
    rep(i,m) {
      int a,b,c;
      tie(a,b,c) = edges[i];
      if(!ok[a] || !ok[b]) continue;
      if(chmin(d[b], d[a] + c)) upd = true;
      if(step > n){
        cout << "inf" << endl;
        return 0;
      }
    }
  }
  cout << -d[n-1] << endl;
}
