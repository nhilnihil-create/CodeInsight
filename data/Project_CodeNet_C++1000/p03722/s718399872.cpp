#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 1000000000000000000
#define MOD 1000000007
#define MAX 3000000
using Graph=vector<vector<int>>;

void dfs(Graph &G,int v,vector<bool> &can_reach){
  can_reach.at(v)=true;
  for(auto nv:G.at(v)){
    if(can_reach.at(nv)){
      continue;
    }
    dfs(G,nv,can_reach);
  }
}

int main(){
  int N,M;
  cin>>N>>M;
  vector<vector<pair<int,ll>>> G(N);
  Graph Gr(N);
  for(int i=0;i<M;i++){
    int a,b;
    int c;
    cin>>a>>b>>c;
    a--;b--;
    G.at(a).push_back(make_pair(b,c));
    Gr.at(b).push_back(a);
  }

  vector<ll> score(N,-INF);
  score.at(0)=0;
  for(int k=0;k<N+1;k++){
    for(int i=0;i<N;i++){
      if(score.at(i)==-INF){
        continue;
      }
      for(auto e:G.at(i)){
        int nv=e.first;
        ll s=e.second;
        if(score.at(nv)<score.at(i)+s){
          score.at(nv)=score.at(i)+s;
        }
      }
    }
  }

  bool loop=false;
  vector<int> A;
  for(int i=0;i<N;i++){
    if(score.at(i)==-INF){
      continue;
    }
    for(auto e:G.at(i)){
      int nv=e.first;
      ll s=e.second;
      if(score.at(nv)<score.at(i)+s){
        loop=true;
        A.push_back(i);
        break;
      }
    }
  }

  if(loop){
    vector<bool> can_reach(N,false);
    dfs(Gr,N-1,can_reach);
    bool flag=false;
    for(auto v:A){
      flag=flag|can_reach.at(v);
    }
    if(flag){
      cout<<"inf"<<endl;
    }else{
      cout<<score.at(N-1)<<endl;
    }
  }else{
    cout<<score.at(N-1)<<endl;
  }

}
