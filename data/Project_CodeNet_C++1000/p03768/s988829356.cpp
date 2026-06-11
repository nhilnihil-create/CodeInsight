#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){

  const int MAX = 11;
  int N, M;
  int q;
  vector<vector<int>> G;
  vector<vector<pair<int,int>>> col;

  cin>>N>>M;

  G.resize(N);
  col.resize(N,vector<pair<int,int>>(MAX,{0ll,-1ll}));


  for(int i = 0; i < M; i++){
    int a, b;

    cin>>a>>b;

    a--, b--;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  cin>>q;

  for(int i = 0; i < q; i++){
    int u, d, c;

    cin>>u>>d>>c;

    u--;

    // col[u][d] = {c, i};

    for(int j = d; j >= 0; j--){
      col[u][j] = {c, i};
    }
  }

  for(int i = 0; i < MAX; i++){
    for(int j = 0; j < N; j++){

      for(int next : G[j]){
        for(int k = MAX-2; k >= 0; k--){
          if(col[j][k+1].second > col[next][k].second) {
            col[next][k] = col[j][k+1];
          }
          if(col[next][k+1].second > col[next][k].second) {
            col[next][k] = col[next][k+1];
          }
        }
      }
      /*
      cout<<"i = "<<i<<" j = "<<j<<endl;

      for(int k = 0; k < MAX; k++){
        cout<<"k = "<<k<<" col = "<<col[j][k].second<<" "<<col[j][k].first<<endl;
      }
      cout<<endl;
      */
    }
  }

  for(int i = 0; i < N; i++){
    cout<<col[i][0].first<<endl;
  }


  return 0;
}
