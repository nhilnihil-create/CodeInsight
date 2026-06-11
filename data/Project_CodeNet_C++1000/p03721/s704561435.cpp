#include<bits/stdc++.h>
using namespace std;

int main(){
  
  long long N, K, a, b, i, Num=0;
  cin>>N>>K;
  map<long long, long long> Data;
  
  for(i=0; i<N; i++){
    cin>>a>>b;
    Data[a]+=b;
  }
  
  for(auto p : Data){
    Num+=p.second;
    if(Num>=K){
      cout<<p.first<<endl;
      return 0;
    }
  }
  return 0;
}