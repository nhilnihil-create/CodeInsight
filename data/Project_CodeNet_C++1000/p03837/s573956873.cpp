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
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

const ll maxv=105;
int dist[maxv][maxv];
int n;
void warshallfloyd(){
  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i ++)
      for(int j = 0; j < n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
 
 
signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll m; cin>>n>>m;
  rep(i,n) rep(j,n) dist[i][j]=INF;
  vector<tuple<ll,ll,ll>> es;
  rep(i,m){
    ll a,b,c; cin>>a>>b>>c;
    a--,b--;
    es.emplace_back(a,b,c);
    dist[a][b]=dist[b][a]=c;
  }
  
  warshallfloyd();
  
  ll ans=0;
  rep(i,m){
    ll a,b,c;
    tie(a,b,c)=es[i];
    if(dist[a][b]<c) ans++;
  }
  cout<<ans<<endl;
}