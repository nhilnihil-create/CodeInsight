#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,K;
  cin>>N>>K;
  
  map<int64_t,int64_t> dic;
  for(int i=0;i<N;i++){
    int64_t a,b;
    cin>>a>>b;
    dic[a]+=b;
  }
  int64_t sum=0;
  for(auto & x:dic){
    sum+=x.second;
    if(sum>=K){
      cout<<x.first<<endl;
      return 0;
    }
  }
    
    
}