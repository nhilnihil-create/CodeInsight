#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define allR(v) v.rbegin(), v.rend()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
typedef pair<int,int> Pi;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
const int inf = 1001001001;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }

template<class T> struct edge { int to; T cost;};


int N,M;
vector<vector<int>> cost;
vector<vector<bool>> used;
vector<vector<edge<int>>> G;

void dijkstra(int s, int t, vector<int> &dist){
  dist[s] = 0;
  priority_queue<Pi> que;
  que.push({0, s});
  while (!que.empty()){
    auto p = que.top(); que.pop();
    int d = p.first;
    int v = p.second;
    for (auto e : G[v]){
      int nv = e.to;
      int c = e.cost;
      if (d+c >= dist[nv]) continue;
      dist[nv] = d + c;
      que.push({dist[nv], nv});
    }
  }
  // s -> t の最短距離はOK
  queue<int> que2;
  que2.push(t);
  while (!que2.empty()){
    int v = que2.front(); que2.pop();
    for (auto e : G[v]){
      int nv = e.to;
      int c = e.cost;
      if (dist[nv]+c == dist[v]){
        used[v][nv] = true;
        used[nv][v] = true;
        que2.push(nv);
      }
    }
  }
}

int main() {
  cin >>N >>M;
  G.assign(N, vector<edge<int>>());
  cost.assign(N, vector<int>(N, -1));
  used.assign(N, vector<bool>(N, false));
  rep(i, M){
    int a,b,c; cin >>a >>b >>c;
    a--; b--;
    G[a].push_back({b,c});
    G[b].push_back({a,c});
    cost[a][b] = c;
    cost[b][a] = c;
  }
  for (int s=0; s<N; s++){
    for (int t=s+1; t<N; t++){
      vector<int> dist(N, 1000000000);
      dijkstra(s, t, dist);
    }
  }
  int res = 0;
  for (int i=0; i<N; i++){
    for (int j=i+1; j<N; j++){
      if (cost[i][j]>=0 && !used[i][j]) res++;
    }
  }
  cout <<res <<endl;
}