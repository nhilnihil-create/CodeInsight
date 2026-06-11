#include <bits/stdc++.h>
const int INF=1e9;
using namespace std;

int main(){
  int n,m,cnt=0; cin>>n>>m;
  vector<vector<pair<int,int>>> g(n);
  vector<vector<int>> d(n,vector<int>(n,INF));

  for(int i=0; i<m; i++){
    int a,b,c; cin>>a>>b>>c;
    a--; b--;
    g[a].emplace_back(b,c);
    g[b].emplace_back(a,c);
  }

  for(int i=0; i<n; i++) d[i][i] = 0;

  for(int i=0; i<n; i++){
     for(auto itr : g[i]){
       d[i][itr.first] = itr.second;
    }
  }

  for(int k=0; k<n; k++){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }

  for(int i=0; i<n; i++){
    for(auto itr : g[i]){
      int j,distance;
      bool trace = false;
      j= itr.first;
      distance = itr.second;
      if(i > j) continue;

      for(int k=0; k<n; k++){
        if(distance + d[j][k] == d[i][k])
          trace = true;
      }
      if(! trace) cnt++;
    }
  }

  cout<<cnt<<endl;

  return 0;

}