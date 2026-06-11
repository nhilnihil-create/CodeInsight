#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
using namespace std;
using ll=long long;

int main(){
  ll N, C, K; cin>>N>>C>>K;
  vector<ll> T(N);
  for(ll i=0; i<N; i++) cin>>T[i];
  sort(T.begin(), T.end());
  ll t=T[0]+K;
  ll b=1;
  ll ans=0;
  for(ll i=1; i<N; i++){
    if(T[i]>t || b==C){
      ans++;
      b=1;
      t=T[i]+K;
      continue;
    }
    b++;
  }
  cout<<ans+1<<endl;
}