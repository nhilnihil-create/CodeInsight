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
long long LCM(long long A,long long B){
  long long g=GCD(A,B);
  return A/g*B;
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
  
  int N;
  cin>>N;
  
  vector<long long> T(N);
  for(int i=0;i<N;i++){
    cin>>T[i];
  }
  
  long long ans=1;
  
  for(int i=0;i<N;i++){
    ans=LCM(ans,T[i]);
  }
  
  cout<<ans<<endl;
}