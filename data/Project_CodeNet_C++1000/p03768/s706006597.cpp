#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define INF 1LL<<50
#define fst first
#define sec second
#define pb push_back
#define int long long
#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(int itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(int itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define debug(x)  cout << #x << " = " << (x) << endl;
typedef long long ll;
typedef pair<ll,ll> P;

int color[100001] = {};
int dist[100001] = {};
vector <int>edge[100001];

void dfs(int v, int d, int c){
  if(color[v] == 0) color[v] = c; //未訪問なら色づけ
  if(dist[v] >= d) return; // すでにその点からd以下の点は訪問済み
  dist[v] = d;
  REP(i,edge[v].size()){
    dfs(edge[v][i],d-1,c);
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  

  REP(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  
  int q;
  cin >> q;
  
  vector<tuple<int,int,int>> tp;
  REP(_,q){
    int v,d,c;
    cin >> v >> d >> c;
    tp.pb(make_tuple(v-1,d,c));
  }
  
  RREP(i,q){
    int v,d,c;
    tie(v,d,c) = tp[i];
    dfs(v,d,c);
  }
  
  REP(i,n) cout << color[i] << endl;

  return 0;
}