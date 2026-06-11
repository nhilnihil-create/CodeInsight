#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N,vector<int>(M));
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      cin >> A[i][j];
      --A[i][j];
    }
  }
  int ans = N;
  vector<bool> C(M,false);
  for(int i = 0; i < M; ++i){
    vector<int> P(M,0);
    for(int j = 0; j < N; ++j){
      for(int k = 0; k < M; ++k){
        if(C[A[j][k]]) continue;
        ++P[A[j][k]];
        break;
      }
    }
    int idx = max_element(P.begin(), P.end()) - P.begin();
    //cerr << i << " " << P[idx] << endl;
    ans = min(ans,P[idx]);
    C[idx] = true;
  }
  cout << ans << endl;
}
