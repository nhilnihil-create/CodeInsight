#include <bits/stdc++.h>
using namespace std;



int main(){
  int64_t N,M;
  cin>>N>>M;
  map<int64_t,int64_t> kaz;
  for(int i=0;i<M;i++){
    int64_t a,b;
    cin>>a>>b;
    if(min(a,b)==1){
      kaz[max(a,b)]++;
    }
    if(max(a,b)==N){
      kaz[min(a,b)]++;
    }
  }
  for(auto & x:kaz){
    if(x.second>=2){
      cout<<"POSSIBLE"<<endl;
      return 0;
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
  
}