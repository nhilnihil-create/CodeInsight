#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const ll inf=1ll<<60;

vector<int> to[2510];
vector<int> rto[2510];
bool reachablefrom1[2510];
bool reachabletoN[2510];
bool ok[2510];

void dfs(int v){
  if(reachablefrom1[v]) return;
  reachablefrom1[v]=1;
  for(int nv:to[v]){
    dfs(nv);
  }
}
void rdfs(int v){
  if(reachabletoN[v]) return;
  reachabletoN[v]=1;
  for(int nv:rto[v]){
    rdfs(nv);
  }
}

int main(){
  int n,m;
  cin >> n >> m;
  vector<tiii> edges;
  rep(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    edges.emplace_back(a,b,-c);
    to[a].push_back(b);
    rto[b].push_back(a);
  }
  dfs(0);
  rdfs(n-1);
  rep(i,n) ok[i]=reachablefrom1[i]&&reachabletoN[i];
  // bellman-ford
  vector<ll> dist(n,inf);
  dist[0]=0;
  bool update=true;
  int step=0;
  while(update){
    update=false;
    rep(i,m){
      int a,b,c;
      tie(a,b,c)=edges[i];
      if(!ok[a]||!ok[b]) continue;
      if(dist[a]+c<dist[b]){
        update=true;
        dist[b]=dist[a]+c;
      }
    }
    step++;
    if(step>n){
      cout << "inf" << endl;
      return 0;
    }
  }
  ll ans=-dist[n-1];
  cout << ans << endl;
}
