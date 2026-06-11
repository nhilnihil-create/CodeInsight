#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll K,S;
  cin>>K>>S;
  if(S<=K) {
cout<<(S+2)*(S+1)/2<<endl;
  return 0;
  }
  
  else if(S<=2*K) {
cout<<(S+2)*(S+1)/2-(S-K)*(S-K+1)/2*3<<endl;
  }
  
  else {
    ll a=(S+2)*(S+1)/2;
    ll b=(S-2*K)*(S-2*K-1)/2;
    ll c=(S-K)*(S-K+1)/2;
    cout<<a+3*b-3*c<<endl;
  }
}
    
 
  