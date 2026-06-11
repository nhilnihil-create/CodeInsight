#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//#include<boost/multiprecision/cpp_int.hpp>
//#include<boost/multiprecision/cpp_dec_float.hpp>
//namespace mp=boost::multiprecision;
//#define mulint mp::cpp_int
//#define mulfloat mp::cpp_dec_float_100
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
constexpr int MOD=1000000007;
//constexpr int MOD=998244353;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcountll(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=2e5+5;
//struct edge{lint to,num;};

struct edge{lint to,cost;};
lint V;
vector<edge> G[200000]; // MAX_V
lint d[200000]; // MAX_V
void dijkstra(lint S){
  priority_queue<plint,vector<plint>,greater<plint>> que;
  fill(d,d+V,LINF);
  d[S]=0;
  que.push(plint(0,S));
  while(!que.empty()){
    plint p=que.top();
    que.pop();
    lint v=p.second;
    if(d[v]<p.first) continue;
    rep(i,G[v].size()){
      edge e=G[v][i];
      if(d[e.to]>d[v]+e.cost){
        d[e.to]=d[v]+e.cost;
        que.push(plint(d[e.to],e.to));
      }
    }
  }
}


int main(void){
    int N,M;
    cin >> N >> M;
    V=N;
    rep(i,M){
        int u,v;
        cin >> u >> v;
        u--,v--;
        G[u].push_back({v,1});
        G[v].push_back({u,1});
    }
    dijkstra(0);
    if(d[N-1]==2) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}