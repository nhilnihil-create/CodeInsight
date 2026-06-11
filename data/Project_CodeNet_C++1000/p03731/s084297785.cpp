#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  ll n,t;cin>>n>>t;
  vector<ll> vec(n);
  rep(i,n)cin>>vec[i];
  int ans=t;
  rep(i,n-1){
    ans+=min(t,vec[i+1]-vec[i]);
  }
  cout<<ans<<endl;
}