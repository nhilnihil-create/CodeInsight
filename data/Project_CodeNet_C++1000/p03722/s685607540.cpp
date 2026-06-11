#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (long long i = (long long)(0); i < (long long)(n); ++i)
#define reps(i, n) for (long long i = (long long)(1); i <= (long long)(n); ++i)
#define rrep(i, n) for (long long i = ((long long)(n)-1); i >= 0; i--)
#define rreps(i, n) for (long long i = ((long long)(n)); i > 0; i--)
#define irep(i, m, n) for (long long i = (long long)(m); i < (long long)(n); ++i)
#define ireps(i, m, n) for (long long i = (long long)(m); i <= (long long)(n); ++i)
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
#define sz(x) long long(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

const ll maxn_bellmanford=2505;
vector<vll> G(maxn_bellmanford);
bool reachableFrom1[maxn_bellmanford];
void dfs(ll v){
  if(reachableFrom1[v]) return;
  reachableFrom1[v]=true;
  for(auto nv: G[v]){
    dfs(nv);
  }
}

vector<vll> rG(maxn_bellmanford);
bool reachableToN[maxn_bellmanford];
void rdfs(ll v){
  if(reachableToN[v]) return;
  reachableToN[v]=true;
  for(auto nv: rG[v]){
    rdfs(nv);
  }
}

ll n,m;
vector<tuple<ll,ll,ll>> es;
ll dist[maxn_bellmanford];
bool ok[maxn_bellmanford];

bool bellmanford(ll s){
  fill(dist,dist+n,LINF);
  dist[s]=0;
  bool update=true;
  ll cnt=0;
  while(update){
    update=false;
    for(auto e: es){
      ll a,b,c;
      tie(a,b,c)=e;
      if(!ok[a]||!ok[b]) continue;
      if(chmin(dist[b],dist[a]+c)) update=true;
    }
    if(cnt>=n){
      return true; // has negative loop
    }
    cnt++;
  }
  return false;
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  cin>>n>>m;
  rep(i,m){
    ll a,b,c; cin>>a>>b>>c; a--,b--; c=-c;
    G[a].push_back(b);
    rG[b].push_back(a);
    es.emplace_back(a,b,c);
  }
  
  dfs(0);
  rdfs(n-1);
  rep(i,n) ok[i]=reachableFrom1[i]&&reachableToN[i];
  
  if(bellmanford(0)){
    cout<<"inf"<<endl;
  }else{
    ll ans=-dist[n-1];
    cout<<ans<<endl;
  }
  
  
}