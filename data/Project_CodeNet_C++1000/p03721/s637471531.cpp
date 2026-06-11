#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,K;
  cin>>N>>K;
  map<int64_t,int64_t> A;
  for(int64_t i=0;i<N;i++){
    int64_t a,b;
    cin>>a>>b;
    A[a]+=b;
  }
  int64_t j=0;
  for(pair<int64_t,int64_t> i:A){
    j+=i.second;
    if(j>=K){
      cout<<i.first<<endl;
      return 0;
    }
  }
}