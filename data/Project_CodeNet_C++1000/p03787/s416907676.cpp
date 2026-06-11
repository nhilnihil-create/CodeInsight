#include <iostream>
#include <vector>
using namespace std;

int dfs(const vector<vector<int>> &G, int v, vector<int> &C){
  int c = C[v], ret = 1;
  for(auto v_ : G[v]){
    if(C[v_] < 0){
      C[v_] = 1-c;
      ret &= dfs(G,v_,C);
    }else if(C[v_] == c){
      ret = 0;
    }
  }
  return ret;
}

int main(){
  long long N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for(int i = 0; i < M; ++i){
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> C(N,-1);
  long long x = 0, y = 0, z = 0;
  for(int i = 0; i < N; ++i){
    if(C[i] >= 0) continue;
    C[i] = 0;
    if(G[i].empty()) ++y;
    else ++z, x += dfs(G,i,C);
  }
  long long ans = N*N - (N-y)*(N-y) + z*z + x*x;
  cout << ans << endl;
}
