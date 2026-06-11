#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
const ll MOD=1000000007;

int main() {
  ll N,M; cin>>N>>M;
  ll ans;
  if(N>=M/2)
  {
    ans=M/2;
  }
  else
  {
    ans=N+(M/2-N)/2;
  }
  cout<<ans<<endl;
  return 0;
}