#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N,M;
  cin>>N>>M;
  vector<vector<long long>>G(N);
  vector<set<long long>>K(N);
  for(int i=0;i<M;i++){
    long long a,b;
    cin>>a>>b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
    K[a].insert(b);
    K[b].insert(a);
  }
  bool flag=false;
  if(G[0].size()>0&&G[N-1].size()>0){
    for(int i=0;i<G[0].size();i++){
      if(K[N-1].count(G[0][i])){
        flag=true;
      }
    }
  }
  if(flag){
    cout<<"POSSIBLE"<<endl;
  }
  else{
    cout<<"IMPOSSIBLE"<<endl;
  }
}