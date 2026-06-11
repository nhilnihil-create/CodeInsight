#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pp=pair<ll,pair<int,int>>;
using Graph=vector<vector<int>>;

int main(){
  int N,M;
  cin>>N>>M;
  Graph G(N);
  for(int i=0;i<M;i++){
    int A,B;
    cin>>A>>B;
    A--;B--;
    G.at(A).push_back(B);
    G.at(B).push_back(A);
  }

  vector<bool> seen(N,false);
  vector<int> ans;
  bool flag=true;
  seen.at(0)=true;
  int v=0;
  ans.push_back(0);
  while(flag){
    flag=false;
    for(auto nv:G.at(v)){
      if(seen.at(nv)){
        continue;
      }
      flag=true;
      seen.at(nv)=true;
      ans.push_back(nv);
      v=nv;
      break;
    }
  }
  flag=true;
  v=0;
  vector<int> ans2;
  while(flag){
    flag=false;
    for(auto nv:G.at(v)){
      if(seen.at(nv)){
        continue;
      }
      flag=true;
      seen.at(nv)=true;
      ans2.push_back(nv);
      v=nv;
      break;
    }
  }

  cout<<ans.size()+ans2.size()<<endl;
  for(int i=ans2.size()-1;i>=0;i--){
    cout<<ans2.at(i)+1<<" ";
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans.at(i)+1<<" ";
  }
  cout<<endl;
}
