#include<bits/stdc++.h>
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;

int main(){
  ll n,m;cin>>n>>m;
  ll mod=7+1e9;
  ll ans=1;
  if(n<m)swap(n,m);
  if(n-m>1)ans=0;

  rep(i,m)ans=ans*(i+1)%mod*(i+1)%mod;
  rep(i,n-m)ans=ans*(m+i+1)%mod;
  if(n==m)ans=ans*2%mod;
  cout<<ans<<endl;
}
