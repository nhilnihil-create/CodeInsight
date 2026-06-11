#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dfs(vector< vector<int> > &G, vector<int> &A, vector<int> &B, int v, int d, int c){
  int ret = 0;
  if(B[v] >= d) return ret;
  B[v] = d;
  if(!A[v]) A[v] = c, ++ret;
  for(int i = 0; i < G[v].size(); ++i){
    int v_ = G[v][i];
    if(B[v_] >= d-1) continue;
    ret += dfs(G,A,B,v_,d-1,c);
  }
  return ret;
}

int main(){
  int N, M;
  cin >> N >> M;
  vector< vector<int> > G(N);
  for(int i = 0; i < M; ++i){
    int a,b;
    cin >> a >> b;
    --a,--b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  // vector< vector< vector<int> > > H(N, vector< vector<int> >(11,vector<int>()));
  // for(int i = 0; i < N; ++i){
  //   vector<bool> used(N,false);
  //   H[i][0].push_back(i);
  //   used[i] = true;
  //   for(int j = 0; j < 10; ++j){
  //     for(int k = 0; k < H[i][j].size(); ++k){
  //       int v = H[i][j][k];
  //       for(int l = 0; l < G[v].size(); ++l){
  //         if(used[G[v][l]]) continue;
  //         used[G[v][l]] = true;
  //         H[i][j+1].push_back(G[v][l]);
  //       }
  //     }
  //   }
  // }
  int Q;
  cin >> Q;
  vector<int> V(Q), D(Q), C(Q);
  for(int i = 0; i < Q; ++i) cin >> V[i] >> D[i] >> C[i];
  reverse(V.begin(), V.end());
  reverse(D.begin(), D.end());
  reverse(C.begin(), C.end());
  vector<int> A(N,0), B(N,-1);
  int colored = N;
  for(int i = 0; i < Q; ++i){
    int v = V[i], d = D[i], c = C[i];
    --v;
    colored -= dfs(G,A,B,v,d,c);
    if(!colored) break;
  }
  for(int i = 0; i < N; ++i) cout << A[i] << endl;
  return 0;
}
