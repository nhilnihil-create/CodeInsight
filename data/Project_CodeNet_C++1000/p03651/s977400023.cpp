#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,K,g=0,m=0;
  cin>>N>>K;
  while(N--){
    int i;
    cin>>i;
    g=__gcd(g,i),m=max(m,i);
  }
  if(m<K || K%g!=0) puts("IMPOSSIBLE");
  else puts("POSSIBLE");
}