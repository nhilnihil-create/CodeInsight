#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  ll a,b,c;cin>>a>>b>>c;
  if(a%2==0||b%2==0||c%2==0)cout<<0<<endl;
  else{
    ll ans=min({a*b,b*c,c*a});
    cout<<ans<<endl;
  }
}