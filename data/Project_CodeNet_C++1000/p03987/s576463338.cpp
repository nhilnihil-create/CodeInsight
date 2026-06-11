#include<bits/stdc++.h>
using namespace std;
int main(){
 int64_t N;
  cin>>N;
  map<int64_t,int64_t>M;
  for(int64_t i=1;i<=N;i++){
    int64_t a; cin>>a;
    M[a]=i;
  }set<int64_t>S;set<int64_t>S1;
  S.insert(0);S.insert(N+1);
  S1.insert(0);S1.insert(-N-1);
  int64_t ans=0;
  for(auto p:M){
  auto k=p.first;
    auto v=p.second;
    auto x=S.upper_bound(v);
    int64_t r=*x-v;
    S.insert(v);
    v*=-1;
    auto y=S1.upper_bound(v);
    int64_t l=*y-v;
    S1.insert(v);
    ans+=k*r*l;
  
  }cout<<ans<<endl;
 
  return 0;
}