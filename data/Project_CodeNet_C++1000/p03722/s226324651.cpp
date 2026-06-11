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

struct edge { ll from, to, cost; };

const ll MAXE = 2005;
edge es[MAXE];          // 辺. edge struct

const ll MAXV = 1005;
ll d[MAXV];            // 最短距離格納用
ll V, E;               // 頂点数, 辺数

bool nega=false;

// s番目の頂点から各頂点への最短経路を求める
void shortest_path(ll s){
  
  for(ll i = 0; i < V; i++) d[i] = LINF;
  d[s] = 0;
  
  rep(i,V*2+1){
    
    bool update = false; // コストが更新されたかの判定用
    
    // esの先頭から順に辺を取り出す. 頂点sをfromとする辺から計算が始まる
    for(ll j = 0; j < E; j++){
      edge e = es[j]; // 辺を取り出す
      // 辺のfrom側の頂点がINFではない(つまり初期化もしくは計算済み)、かつ、辺のto側の頂点がfromからのコストより大きい場合、そのコストを更新する
      if(d[e.from] != LINF && d[e.to] > d[e.from] + e.cost){ // 負の閉路があるならば、d[e.to] > d[e.from] + e.cost が常にtrueとなる無限ループとなる
        d[e.to] = d[e.from] + e.cost;
        if(e.to == V-1 && i==V*2) nega=true;
      }
    }
  }
}

// 負の閉路が存在するかを判定する
bool find_negative_loop(){
  memset(d, 0, sizeof(d));
  
  // 負の閉路が存在しないならば、V-1(頂点数-1)回のループで更新は発生しなくなる. 
  // 1回のイテレーションでは、少なくとも1つの頂点が定まる. このうち始点となる頂点は初めからコストが定めているため、負閉路がない場合のループ回数はV-1回となる
  for(ll i = 0; i < V; i++){
    for(ll j =0; j < E; j++){
      edge e = es[j];
      if(d[e.to] > d[e.from] + e.cost){
        d[e.to] = d[e.from] + e.cost;
        
        // V回目のループは全頂点についてのコスト計算を終え、2周目を意味する
        // 2周目で更新があるという事は、常にコストが減少し続ける負閉路が存在することになる
        if(i == V-1) return true;
      }
    }
  }
  return false;
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  cin>>V>>E;
  rep(i,E){
    ll a,b,c; cin>>a>>b>>c;
    a--,b--; c*=-1;
    es[i]=edge{a,b,c};
  }
  
  shortest_path(0);
  
  if(nega){
    puts("inf");
  }else{
    cout<<-d[V-1]<<endl;
  }
  
}