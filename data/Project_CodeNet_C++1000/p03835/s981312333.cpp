#include <bits/stdc++.h>

using namespace std;

int main() {
  int k,s;
  cin>>k>>s;
  if(s<=k){
    cout<<((s+2)*(s+1))/2<<endl;
    return 0;
  }
  if(s<2*k){
    cout<<(k+1)*(k+2)/2-(s-k)*(s-k+1)/2+k*(k+1)/2-(2*k-s)*(2*k-s+1)/2<<endl;
    return 0;
  }
  cout<<(3*k-s+1)*(3*k-s+2)/2<<endl;
  
  
}