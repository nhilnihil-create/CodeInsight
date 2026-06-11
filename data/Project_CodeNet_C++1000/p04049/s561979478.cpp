#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;

int count(const vector< vector<int> > &G, int v, int p, int dist, int dist_max){
  if(dist > dist_max) return 0;
  int ret = 1;
  for(size_t i = 0; i < G[v].size(); ++i){
    int v_ = G[v][i];
    if(v_ == p) continue;
    ret += count(G,v_,v,dist+1,dist_max);
  }
  return ret;
}

int main(){
  int N, K;
  cin >> N >> K;
  vector< vector<int> > T(N);
  for(int i = 0; i < N-1; ++i){
    int a, b;
    cin >> a >> b;
    --a,--b;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  int ans = N;
  if(K%2){
    for(int i = 0; i < N; ++i){
      for(size_t j = 0; j < T[i].size(); ++j){
        int k = T[i][j];
        ans = min(ans,N-count(T,i,k,0,K/2)-count(T,k,i,0,K/2));
      }
    }
  }else{
    for(int i = 0; i < N; ++i){
      ans = min(ans,N-count(T,i,-1,0,K/2));
    }
  }
  cout << ans << endl;
}
