#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
#define MOD 1000000007;
using namespace std;
long long GCD(long long A,long long B){
  if(B==0){
    return A;
  }
  else{
    return GCD(B,A%B);
  }
}
long long num_size(long long X){
  int ans=0;
  while(true){
    if(X==0){
      break;
    }
    else{
      X/=10;
      ans++;
    }
  }
  return ans;
}
int main() {
  
  long long N;
  cin>>N;
  
  long long ans=1000000000;
  
  
  for(int i=1;i<=pow(N,0.5);i++){
    if(N%i==0){
      ans=min(ans,max(num_size(i),num_size(N/i)));
    }
  }
  
  cout<<ans<<endl;
}