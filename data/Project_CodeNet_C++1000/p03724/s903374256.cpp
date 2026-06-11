#include<bits/stdc++.h>
using namespace std;
int main(){
int N,m;
  cin>>N>>m;
  map<int,int>M;
  for(int i=0;i<2*m;i++){
  int a; cin>>a;
    if(M.count(a))
    M.at(a)++;
    else
      M[a]=1;
    }bool ans=true;
  for(auto p:M){
  auto k=p.first;
    auto v=p.second;
    if(v%2==1){
      ans=false; break;
    }
  }if(ans)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
    return 0;
}
