#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<assert.h>
#include<string>
#include<cstdlib>
#include<cctype>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<stack>
// #include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 1LL<<60;
constexpr int inf = 1e9;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};

// intやllをstringに変換
template<typename T> inline string toString(const T &a){
  ostringstream oss;
  oss << a;
  return oss.str();
};
// ----------------------------------------------------------------------------
struct edge{
  int from;
  int to;
  int cost;
};

int main(){
  int N,M;
  cin >> N >> M;
  vector<edge> G(M);
  for(int i=0; i<M; i++){
    cin >> G[i].from >> G[i].to >> G[i].cost;
    G[i].from--;
    G[i].to--;
  }
  vector<vector<int>> dist(N, vector<int> (N));
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i==j){
        dist[i][j] = 0;
      }else{
        dist[i][j] = inf;
      }
    }
  }
  for(int i=0; i<M; i++){
    chmin(dist[G[i].from][G[i].to],G[i].cost);
    chmin(dist[G[i].to][G[i].from],G[i].cost);
  }
  for(int k=0; k<N; k++){
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        chmin(dist[i][j], dist[i][k]+dist[k][j]);
      }
    }
  }
  int ans = 0;
  for(int i=0; i<M; i++){
    bool sh = false;
    for(int j=0; j<N; j++){
      if(dist[j][G[i].from]+G[i].cost == dist[j][G[i].to]) sh = true;
    }
    if(sh){
      ans++;
    }
  }
  cout << M-ans << endl;
  return 0;
}
