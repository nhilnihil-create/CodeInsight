#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1};
vector<int> y4 = {1, 0, -1, 0};
vector<int> x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
  T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }


template<class T> struct edge { int from, to; T cost;};

int N,M; // 各々頂点数、辺数
const int MAX_N = 1000;
const int MAX_M = 2000;
vector<ll> d(MAX_N);   // 最短距離             // llにするときは(ry
vector<edge<ll>> es(MAX_M); // 辺              // llにするときはここもllにしてくれ
vector<bool> negative(MAX_N);

// s番目の頂点から各頂点への最短距離を求める。但しtrueならアカン負の閉路が存在する
bool bellman_ford(int s){
  rep(i, N) d[i] = INF;
  d[s] = 0;
  rep(vv, N-1){
    rep(i, M){
      auto e = es[i];
      if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) d[e.to] = d[e.from] + e.cost;
    }
  }
  bool nclose = false;
  rep(vv, N-1){ // 離島、負の閉路について
    rep(i, M){
      auto e = es[i];
      if (d[e.from] == INF) continue;
      if (d[e.from] + e.cost < d[e.to]) negative[e.from] = true, nclose = true;
      if (negative[e.from]) negative[e.to] = true;
    }
  }
  return nclose;
}


int main() {
  cin >>N >>M;
  rep(i, M){
    int a,b; ll c; cin >>a >>b >>c; a--; b--; c = -c;
    es[i] = {a,b,c};
  }
  bellman_ford(0);
  if (negative[N-1]) cout <<"inf" <<endl;
  else{
    cout <<-d[N-1] <<endl;
  }
}
