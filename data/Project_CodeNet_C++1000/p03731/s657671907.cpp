#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll N,T;cin>>N>>T;
  vector<ll> t(N);rep(i,N) cin>>t[i];
  
  ll ans=0;
  for(int i=0;i<=N-2;i++){
    if(t[i+1]-t[i]>T) ans+=T;
    else ans+=t[i+1]-t[i];
  }
  
  cout << ans+T << endl;
}
