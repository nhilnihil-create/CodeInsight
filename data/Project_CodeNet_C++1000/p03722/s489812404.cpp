#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) int(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e15;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll n,m;
vector<tuple<ll,ll,ll>> es;
vll G[1005];
vll rG[1005];

bool reachable[1005];
bool rReachable[1005];
void dfs(ll v){
  reachable[v]=true;
  for(auto nv:G[v]){
    if(reachable[nv]) continue;
    dfs(nv);
  }
}

void rdfs(ll v){
  rReachable[v]=true;
  for(auto nv:rG[v]){
    if(rReachable[nv]) continue;
    rdfs(nv);
  }
}

ll dist[1005];

bool bellmanford(ll s){
  vector<bool> ok(n);
  rep(i,n) ok[i]=reachable[i]&&rReachable[i];
  rep(i,n) dist[i]=LINF;
  dist[s]=0;
  bool update=true;
  ll cnt=0;
  while(update){
    update=false;
    for(auto e: es){
      ll a,b,c;
      tie(a,b,c)=e;
      if(!ok[a]||!ok[b]) continue;
      if(dist[a]!=INF&&chmin(dist[b],dist[a]+c)){
        update=true;
      }
    }
    
    if(cnt>=n){
      return true;
    }
    cnt++;
  }
  return false;
}


signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  cin>>n>>m;
  es.resize(m);
  rep(i,m){
    ll a,b,c; cin>>a>>b>>c;
    a--,b--;
    es.emplace_back(a,b,-c);
    G[a].push_back(b);
    rG[b].push_back(a);
  }
  dfs(0);
  rdfs(n-1);
  if(bellmanford(0)){
    puts("inf");
  }else{
    cout<<-dist[n-1]<<endl;
  }
}