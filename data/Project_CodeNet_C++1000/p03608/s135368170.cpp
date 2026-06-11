#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define all(x) (x).begin(),(x).end()
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
using Graph = vector<vector<int>>;
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}
struct edge{ll to, cost;};
typedef pair<ll,ll> P;
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    rep(i,V){
      d[i] = INF;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    rep(i,V){
      d[i] = INF;
    }
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P> > que;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
};
int main(){
ll n,m,r;
cin>>n>>m>>r;
ll c[r]={};
rep(i,r){
  cin>>c[i];
  c[i]--;}
  sort(c,c+r);
  vvl dist(n, vl(n,INF));
  for(ll i=0; i<m; i++){
    ll a,b,c; cin>>a>>b>>c;
    dist[a-1][b-1]=c;
    dist[b-1][a-1]=c;}
  
  for (ll k = 0; k < n; k++){       // 経由する頂点
    for (ll i = 0; i < n; i++) {    // 始点
      for (ll j = 0; j < n; j++) {  // 終点
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
ll ca = 1;
  for(ll i=1; i<=r; i++){
    ca*=i;}
  ll ans = INF;
  ll cb = 0;
  for(ll i=0; i<ca; i++){
    next_permutation(c,c+r);
    cb = 0;
    for(ll j=0; j<r-1; j++){
      cb += dist[c[j]][c[j+1]];}
    ans = min(ans,cb);
  }
  cout << ans << endl;}
  
    
  
  
    
