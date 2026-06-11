#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,K;
  cin>>N>>K;
  ll ans=K;
  for(ll i=0;i<N-1;i++) {
ans*=(K-1);
  }
  cout<<ans<<endl;
}
  