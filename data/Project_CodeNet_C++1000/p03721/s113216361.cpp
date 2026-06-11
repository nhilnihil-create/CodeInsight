#include<bits/stdc++.h>
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;

int main(){
  ll n,k;cin>>n>>k;
  int a,b;
  map<int,ll> mp;
  for(int i=1;i<=n;i++){
    cin>>a>>b;
    mp[a]+=b;
  }
  for(auto p : mp){
    auto x=p.first;
    auto y=p.second;
    k-=y;
    if(k<1){
      cout<<x;
      return 0;
    }
  }
}