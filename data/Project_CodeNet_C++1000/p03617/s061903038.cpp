#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int Q,H,S,D,N;
  cin>>Q>>H>>S>>D>>N;
  cout<<(N/2)*min({Q*8,H*4,S*2,D})+(N%2)*min({Q*4,H*2,S})<<endl;
}