//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define itn int
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sort(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=2e9;
const ll lnf=9e18;

int prevv[100010];
struct edge{int to,cost;};

vector<ll> dijkstra(int n,vector<vector<edge> > G,int s){
  fill(prevv,prevv+n,-1);
  priority_queue<pii,vector<pii>,greater<pii> > que;
  vector<ll> dist(n,inf);
  dist[s]=0;
  que.push(pii(0,s));
  while(!que.empty()){
    int c,v;
    tie(c,v)=que.top();
    que.pop();
    if(dist[v]<c) continue;
    for(int i=0;i<G[v].size();i++){
      edge e=G[v][i];
      int nc=e.cost;
      int nv=e.to;
      if(dist[nv]>dist[v]+nc){
        dist[nv]=dist[v]+nc;
        prevv[nv]=v;
        que.push(pii(dist[nv],nv));
      }
    }
  }
  return dist;
}

//頂点への最短路
vector<int> get_path(int t){
  vector<int> path(0);
  for(;t!=-1;t=prevv[t]) path.push_back(t);
  reverse(path.begin(),path.end());
  return path;
}

struct unionfind{
  vector<int> par;
  unionfind(int n):par(n,-1){}
  void init(int n){par.assign(n,-1);}
  int root(int x){
    if(par[x]<0) return x;
    else return par[x]=root(par[x]);
  }
  bool issame(int x,int y){
    return root(x)==root(y);
  }
  bool merge(int x,int y){
    x=root(x); y=root(y);
    if(x==y) return false;
    if(par[x]>par[y]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
    return true;
  }
  int size(int x){
    return -par[root(x)];
  }
};

int main(){
  itn n; cin >> n;
  vector<vector<edge> > g(n,vector<edge>(0));
  vector<vector<int> > g2(n,vector<int>(0));
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back({b,1});
    g[b].push_back({a,1});
    g2[a].push_back(b);
    g2[b].push_back(a);
  }
  vector<ll> dist=dijkstra(n,g,0);
  //cout << dist[n-1] << endl;
  vector<int> path=get_path(n-1);
  itn cutv1=path[(path.size()-1)/2];
  itn cutv2=path[(path.size()+1)/2];
  unionfind uf(n);
  rep(i,n){
    for(auto j:g2[i]){
      if((i==cutv1&&j==cutv2)||i==cutv2&&j==cutv1) continue;
      uf.merge(i,j);
    }
  }
  if(uf.size(0)>uf.size(n-1)) cout << "Fennec" << endl;
  else cout << "Snuke" << endl;
}