#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int Q,H,S,D,N;
  cin>>Q>>H>>S>>D>>N;
  S=min({Q*4,H*2,S});
  cout<<min(S*2,D)*(N/2)+S*(N%2)<<endl;
}