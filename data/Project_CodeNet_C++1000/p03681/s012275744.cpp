#include <bits/stdc++.h>
using namespace std;


int main() {
  int64_t N,M;
  cin>>N>>M;
  
  if(abs(N-M)>=2){
    cout<<0<<endl;
    return 0;
  }
  else{
    if(N==M){
      int64_t sum=1;
      for(int i=N;i>=1;i--){
        sum=(sum*i)%1000000007;
      }
      for(int i=M;i>=1;i--){
        sum=(sum*i)%1000000007;
      }
      sum=(sum*2)%1000000007;
      cout<<sum<<endl;
    }
    else{
      int64_t sum=1;
      for(int i=N;i>=1;i--){
        sum=(sum*i)%1000000007;
      }
      for(int i=M;i>=1;i--){
        sum=(sum*i)%1000000007;
      }
      cout<<sum<<endl;
    }
  }
      
  
}