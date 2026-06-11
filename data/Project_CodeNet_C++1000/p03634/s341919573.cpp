#include <bits/stdc++.h>

using namespace std ;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll ;
typedef vector<int> vint;
typedef vector<double> vdbl ;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vector<int> > vvint;
typedef vector<pair<int,int> > vpii ;
typedef vector<pair<ll,ll> > vpll ;
typedef priority_queue<int, vector<int>, greater<int> > spqint ; //小さい順に取り出し
typedef priority_queue<ll, vector<ll>, greater<ll> > spqll ; //小さい順に取り出し
typedef priority_queue<int, vector<int>, less<int> > bpqint ; //大きい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll> > bpqll ; //大きい順に取り出し


#define REP(i, n) for (int (i) = 0; (i) < (int)(n); i++) 
#define FOR(i, a, b) for(int (i) = a; (i) < (int)b; i++)
#define IREP(i,v) for(auto i=v.begin(); i !=v.end(); i++)
#define MOD 1000000007
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define TS to_string
#define BS binary_search
#define LB lower_bound
#define UB upper_bound
#define NP next_permutation
#define ALL(v) (v).begin(),(v).end()
#define SZ(x)  (ll)x.size()
#define SP(x)  setprecision((ll)x)

const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
const double PI = M_PI;
const int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //最小公倍数

void yes(){
  cout <<"Yes"<<endl ;
}
void no(){
  cout <<"No"<<endl ;
}
//-----------------------------------------

const int MAX_V = 1e6;

struct edge{
  int to ; 
  ll cost ;
  //iからの行き先とそのコストの情報
};

int n ;
vector<edge> G[MAX_V] ;
//G[i]...iからの行き先(to)とコスト(cost)の情報を持つ
ll d[MAX_V] ;
//d[i]...sからiへ行くのにかかるコストの最小

vector<int> par ;
//par[i]...iの一個前


void dijkstra(int s){
  priority_queue<pii, vector<pii>, greater<pii> > que;
  //pair<sからiへ行くのの暫定最小コスト、i>の優先度付きキュー
  REP(i,n){
    d[i] = LINF ;
    par.PB(i) ;
    //はじめコストはINFとして初期化
  }
  d[s] = 0 ;
  que.push(MP(0,s)) ;
  //自身へのコストは0としてqueへ入れる
  
  while(!que.empty()){
    pii p = que.top() ;
    que.pop() ;
    int v = p.SE ;
    //queが空になるまで取り出す
    if(d[v]<p.FI){
      //すでにそれ以下があれば見る必要はない
      continue ;
    }
    REP(i,SZ(G[v])){
      //vを経由した行き先について
      edge e = G[v][i] ;
      if(d[e.to]>d[v]+e.cost){
        //vを経由した方がコストが小さいなら更新し、queに入れる
        d[e.to] = d[v]+e.cost ;
        par[e.to] =  v ;
        que.push(MP(d[e.to],e.to)) ;
      }
    }
  }
}

//頂点tへの最短路
vector<int> get_path(int t){
    vector<int> path;
    int i = t ;
    while(i!=par[i]){
      path.PB(i) ;
      i = par[i] ;
    }
    reverse(ALL(path)) ;
    return path ;
}
//-------------------------------------------------------

/*
const int MAX_V = 1e6;

struct edge{
  int to ; 
  ll cost ;
  //iからの行き先とそのコストの情報
};

int n ;

*/

vector<edge> G2[MAX_V] ;
//G2[i]...iからの行き先(to)とコスト(cost)の情報を持つ
ll d2[MAX_V] ;
//d2[i]...sからiへ行くのにかかるコストの最小

vector<int> par2 ;
//par2[i]...iの一個前

void redijkstra(int s){
  priority_queue<pii, vector<pii>, greater<pii> > que2;
  //pair<sからiへ行くのの暫定最小コスト、i>の優先度付きキュー
  REP(i,n){
    d2[i] = LINF ;
    par2.PB(i) ;
    //はじめコストはINFとして初期化
  }
  d2[s] = 0 ;
  que2.push(MP(0,s)) ;
  //自身へのコストは0としてqueへ入れる
  
  while(!que2.empty()){
    pii p2 = que2.top() ;
    que2.pop() ;
    int v2 = p2.SE ;
    //queが空になるまで取り出す
    if(d2[v2]<p2.FI){
      //すでにそれ以下があれば見る必要はない
      continue ;
    }
    REP(i,SZ(G2[v2])){
      //vを経由した行き先について
      edge e2 = G2[v2][i] ;
      if(d2[e2.to]>d2[v2]+e2.cost){
        //vを経由した方がコストが小さいなら更新し、queに入れる
        d2[e2.to] = d2[v2]+e2.cost ;
        par2[e2.to] =  v2 ;
        que2.push(MP(d2[e2.to],e2.to)) ;
      }
    }
  }
}


















//-----------------------------------------
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n ;
  REP(i,n-1){
      ll a, b, c ;
      cin >> a >> b >> c ;
      edge e = {b-1,c};
      G[a-1].PB(e) ;
      G2[a-1].PB(e) ;
      edge e2 = {a-1,c};
      G[b-1].PB(e2) ;
      G2[b-1].PB(e2) ;
  }
  int q, k ;
  cin >> q >> k ;
  k-- ;
  dijkstra(k) ;
  redijkstra(k) ;
  REP(i,q){
      int x, y ;
      cin >> x >> y ;
      x-- ;
      y-- ;
      cout << d2[x] + d[y] <<endl ;
  }

  
  
  
  return 0 ;
}