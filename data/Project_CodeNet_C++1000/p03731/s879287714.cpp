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
  
  int N,T;
  cin>>N>>T;
  
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec[i];
  }
  
  long long ans=T;
  
  for(int i=0;i<N-1;i++){
    if(vec[i+1]-vec[i]>T){
      ans+=T;
    }
    else{
      ans+=(vec[i+1]-vec[i]);
    }
  }
  
  cout<<ans<<endl;
}