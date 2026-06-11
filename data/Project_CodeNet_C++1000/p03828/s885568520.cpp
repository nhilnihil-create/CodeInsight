#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
using vs = vector<string> ;
#define all(v) v.begin(),v.end()

int main(){
  ll N;cin>>N;
  vll v(1010,0);
  for(int i=2;i<=N;++i){
    ll tmp=2;
    ll i_tmp = i;
    while(i_tmp>1){
      if(i_tmp%tmp==0){
        v[tmp]++;
        i_tmp/=tmp;
      }
      else tmp++;
    }
  }
  ll ans=1;
  ll mod=1e9+7;
  rep(i,N+1){
    if(v[i]>=1){
      ans *= v[i]+1;
      ans %= mod;
    }
  }
  cout<<ans<<endl;
}