#include<bits/stdc++.h>
using namespace std;

int main(){
  
  long long N, M, i, Sum=1;
  cin>>N>>M;
  
  for(i=1; i<=N; i++){
    Sum*=i;
    if(Sum>1000000007) Sum%=1000000007;
  }
  for(i=1; i<=M; i++){
    Sum*=i;
    if(Sum>1000000007) Sum%=1000000007;
  }
  cout<<(Sum*max(2-abs(N-M), 0ll))%1000000007<<endl;
  return 0;
}