#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll int64_t
#define all(v) v.begin(), v.end()
#define bitrep(n) for(int bit=0;bit<(1<<n);bit++)

int main() {

  ll N,M,ans=0; cin >> N >> M ;
  
  if(2*N<=M){//ここの条件ミスった、アホすぎる
    ans+=N;
    ll x=M-2*N;
    ans+=(x/4);
  }

  else{
    ans+=(M/2);
  }
  
  cout << ans << endl;

  return 0;
}