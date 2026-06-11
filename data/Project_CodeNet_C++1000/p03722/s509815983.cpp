#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <complex>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <regex>
#include <limits>
#include <time.h>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <limits.h>
using namespace std;
using pii  = pair<int,int>;
using ll=long long;
using ld=long double;
#define pb push_back
#define mp make_pair
#define sc second
#define fr first
#define stpr setprecision
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define rep(i,n) for(ll i=0;i<(n);++i)
#define Rep(i,a,b) for(ll i=(a);i<(b);++i)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define rRep(i,a,b) for(ll i=a;i>=b;i--)
#define crep(i) for(char i='a';i<='z';++i)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define ALL(x) (x).begin(),(x).end()
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define endl '\n'
int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}
ll gcd(ll a,ll b){return (b == 0 ? a : gcd(b, a%b));}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
constexpr ll MOD=1000000007;
constexpr ll INF=1000000011;
constexpr ll MOD2=998244353;
constexpr ll LINF = 1001002003004005006ll;
constexpr ld EPS=10e-8;
template <class T, class U> inline bool chmax(T& lhs, const U& rhs) { if (lhs < rhs) { lhs = rhs; return 1; } return 0; }
template <class T, class U> inline bool chmin(T& lhs, const U& rhs) { if (lhs > rhs) { lhs = rhs; return 1; } return 0; }
template<typename T> istream& operator>>(istream& is,vector<T>& v){for(auto&& x:v)is >> x;return is;}
template<typename T,typename U> istream& operator>>(istream& is, pair<T,U>& p){ is >> p.first; is >> p.second; return is;}
template<typename T,typename U> ostream& operator>>(ostream& os, const pair<T,U>& p){ os << p.first << ' ' << p.second; return os;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v){
  for(auto i=begin(v); i != end(v); ++i){
    if(i !=begin(v)) os << ' ';
    os << *i;
  }
  return os;
}

// 隣接リストで使う辺を表す型
struct Edge {
    ll to, cost;  // 辺の接続先頂点, 辺の重み
    Edge(ll to, ll cost) : to(to), cost(cost) {}  // コンストラクタ
};

typedef vector<vector<Edge> > AdjList;
AdjList graph;  // グラフの辺を格納した構造体
                // graph[v][i]は頂点vから出るi番目の辺Edge

vector<ll> DIS; // 最短距離
ll C[1007];

// 戻り値がtrueなら負の閉路を含む
bool bellman_ford(ll N, ll s) { // nは頂点数、sは開始頂点
    DIS = vector<ll>(N+2, LINF);
    DIS[s] = 0; // 開始点の距離は0
    rep(i,N+1){
        rep(v,N){          // ここ
            rep(k,graph[v].size()){
                Edge e = graph[v][k];
                if((DIS[v] != INF && DIS[e.to] > DIS[v] + e.cost )&&(C[v]==0 && C[e.to]==0) ) {
                    DIS[e.to] = DIS[v] + e.cost;
                    if(i==N){
                        C[v]=1;
                        C[e.to]=1;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    graph = AdjList(N+2);
  
    rep(i,M){
        ll X, Y, L;
        cin >> X >> Y >> L;
        X--;Y--;
        graph[X].push_back(Edge(Y, -L));
    }
  
    bool F = bellman_ford(N, 0);
    F = bellman_ford(N, 0);
    if(DIS[N-1]==LINF){
      cout <<"inf" << endl;
      return 0;
    }

    cout <<-DIS[N-1]<< endl;

}
