#include<bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

//グラフとして解く

int main(){
  int N, M;
  //頂点の数と辺の数
  cin >> N >> M;
  Graph G(N);
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i = 0; i < N; i++){
    cout << G[i].size() << endl;
  }
}