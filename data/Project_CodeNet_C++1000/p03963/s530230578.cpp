#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  long long N,K;
  cin>>N>>K;
  
  
  if(N==1){
    cout<<K<<endl;
  }
  else{
  long long ans=K*(K-1);
  
  for(int i=0;i<N-2;i++){
    ans*=K-1;
  }
  
  cout<<ans<<endl;
  }
}