#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1e9+7;

#define vec     vector<int>
#define vecll   vector<ll>
#define vec2    vector<vector<int>>
#define vec2ll  vector<vector<ll>>
#define vpair   vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>
#define vecst   vector<string>
#define vecb    vector<bool>

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vecst var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());
#define f_sum(var)       accumulate(all(var), 0)
#define f_sumll(var)     accumulate(all(var), 0LL)
#define chmin(v1, v2)    v1 = min(v1, v2)
#define chmax(v1, v2)    v1 = max(v1, v2)
#define mpair(v1, v2)    make_pair(v1, v2)
#define pb(var)          push_back(var)
#define prt(var)         cout << var << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << var << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << var;
#define prt2(v1, v2)     cout << v1 << " " << v2 << "\n"
#define prt3(v1, v2, v3) cout << v1 << " " << v2 << " " << v3 << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
void prtok(bool ok){prt((ok ? "Yes" : "No"));}
//----------------------------------------------------------------
struct Weight{
  int to;
  int weight;
  Weight(int t, int w) : to(t), weight(w) {}
};

class GraphW{

public:
  vector<vector<Weight>> graphs;
  vector<bool> check; // For DFS
  vector<ll> dist;   // For BFS
  int dijk_count;
  queue<int> q; // For BFS

  bool st_dijk;

  GraphW(int n){
    graphs.resize(n);
    init(n);
    st_dijk=true;
  }
  ~GraphW(){}

  void addedge(int a, int b, int c){
    a--; b--;
    if(c<0){st_dijk=false;}
    graphs[a].push_back(Weight(b, c));
    graphs[b].push_back(Weight(a, c));
  }

  void addedge_cin(int m){
    rep(i,m){
      int a, b, c;
      cin >> a >> b >> c;
      addedge(a, b, c);
    }
  }


  void init(int n){
    check.resize(n, false);
    dist.resize(n, -1);
  }

  void dfs(int v){
    check[v] = true;

    for(auto next_v : graphs[v]){
      if(check[next_v.to]) continue;
      dfs(next_v.to);
    }
  }

  void preDijk(){
    for(int i=0;i<dist.size(); i++){
      dist[i]=LONG_MAX;
    }
    for(int i=0;i<check.size(); i++){
      check[i]=false;
    }
  }

  void dijk(int v){
    for(Weight next_v : graphs[v]){
      dist[next_v.to] = min(dist[next_v.to], dist[v]+next_v.weight);
    }
    check[v] = true;
  }

  void dijkstra(int v)//----------------------
  {
    if(st_dijk){// start
      preDijk();
      dist[v]=0;
      dijk_count=check.size();
      //st_dijk=false;
    } else {
      cout << "Dijkstra can't be applied.\n";
      return;
    }

    while(dijk_count){
      int tmp=-1;
      ll tmpdist=LONG_MAX;

      for(int i=0; i<check.size(); i++){
        if(tmpdist>dist[i] && !check[i]){
          tmpdist=dist[i];
          tmp=i;
        }
      }
      dijk(tmp);
      dijk_count--;
    }
  }
};

int main(void) {
  int N, M;
  cin >> N >> M;

  GraphW g(N);
  vec a(M), b(M), c(M);
  rep(i,M){
    cin >> a[i] >> b[i] >> c[i];
    g.addedge(a[i], b[i], c[i]);
  }

  ll mindist[N][N];
  rep(i,N){
    rep(j,N){
      mindist[i][j]=1e10;
    }
  }

  rep(i,N){
    g.dijkstra(i);
    rep(j,N){
      mindist[i][j]=g.dist[j];
    }
  }

  int ans=0;
  rep(i,M){
    bool ok=true;
    rep(s,N){
      rep(t,N){
        if(mindist[s][a[i]-1]+c[i]+mindist[b[i]-1][t]==mindist[s][t]) ok=false;
      }
    }
    if(ok) ans++;
  }

  prt(ans);

}
