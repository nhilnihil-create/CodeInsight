#include<bits/stdc++.h>
using namespace std;

int main(){

  int N, M, i, j, a, b;
  cin>>N>>M;
  vector<vector<int>> r(N+1);
  for(i=0; i<M; i++){
    cin>>a>>b;
    r[a].push_back(b);
  }
  
  for(i=0; i<(int)r[1].size(); i++){
    for(j=0; j<(int)r[r[1][i]].size(); j++){
      if(r[r[1][i]][j]==N){
        cout<<"POSSIBLE"<<endl;
        return 0;
      }
    }
  } 
  cout<<"IMPOSSIBLE"<<endl;
  return 0;
}