#include<bits/stdc++.h>
using namespace std;
set<int>f(int N){
set<int>S;
  for(int i=2;i<=N;i++){
    bool x=true;
for(int j=2;j<i;j++){
if(i%j==0){x=false; break;}
}  if(x)S.insert(i);
  } return S;
}
int main(){
int N;
  cin>>N;
  set<int>s=f(N);
  map<int64_t,int64_t>M;
  for(auto p:s){
  int a=N;
    int64_t ans=1;
    for(int i=0;0<a;i++){
    a/=p; ans+=a;
    }
  M[p]=ans;
  }
  int64_t ans=1;
for(auto p:M){
auto k=p.first;
  auto v=p.second;
  ans=(ans*v)%1000000007;

}cout<<ans<<endl;
  
   return 0;
}