#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 2100000000
#define MOD 1000000007

int main(){
  ll N;
  ll x;
  cin>>N>>x;
  vector<ll> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }

  vector<vector<ll>> minimum(N,vector<ll>(N));
  for(int i=0;i<N;i++){
    minimum.at(i).at(0)=a.at(i);
  }
  for(int j=1;j<N;j++){
    for(int i=0;i<N;i++){
      minimum.at(i).at(j)=min<ll>(minimum.at((i+N-1)%N).at(j-1),a.at(i));
    }
  }

  ll ans=10000000000000;
  for(ll j=0;j<N;j++){
    ll sub=0;
    for(int i=0;i<N;i++){
      sub+=minimum.at(i).at(j);
    }
    sub+=j*x;
    ans=min<ll>(ans,sub);
  }
  cout<<ans<<endl;
}
