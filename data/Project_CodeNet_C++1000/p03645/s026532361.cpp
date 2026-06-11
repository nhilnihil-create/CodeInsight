#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin>>n>>m;
  map<int,vector<int>>G;
  int a,b;
  for(int i=0;i<m;i++){
    cin>>a;cin>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  if(!G.count(1)){
    cout <<"IMPOSSIBLE"<<endl;
    return 0;
  }
  int size=G[1].size();
  for(int i=0;i<size;i++){
    int size2=G[G[1].at(i)].size();
    for(int j=0;j<size2;j++){
      if(G[G[1].at(i)].at(j)==n){
        cout <<"POSSIBLE"<<endl;
        return 0;
      }
    }
  }
  cout <<"IMPOSSIBLE"<<endl;
}