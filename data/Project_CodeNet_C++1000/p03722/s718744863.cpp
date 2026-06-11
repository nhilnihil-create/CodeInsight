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
    G[i].cost *= -1;
  }
  vector<ll> dist(N,INF);
  dist[0] = 0;
  for(int i=0; i<N-1; i++){
    for(int j=0; j<M; j++){
      chmin(dist[G[j].to],dist[G[j].from] + G[j].cost);
    }
  }
  vector<bool> inf_loop(N,false);
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(chmin(dist[G[j].to],dist[G[j].from]+G[j].cost)){
        inf_loop[G[j].to] = true;
      }
      if(inf_loop[G[j].from]) inf_loop[G[j].to] = true;
    }
  }
  if(inf_loop[N-1]){
    cout << "inf" << endl;
  }else{
    cout << -dist[N-1] << endl;
  }
  return 0;
}
