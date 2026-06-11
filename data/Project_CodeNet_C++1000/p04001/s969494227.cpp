#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  int n=s.size();
  ll ans=0;
  rep(bit,1<<(n-1)){
    ll a=s[0]-'0';
    rep(i,n-1){
      if(bit&(1<<i)){
        ans+=a;
        a=0;
      }
    a=10*a+s[i+1]-'0';
    }
    ans+=a;
  }
  cout<<ans<<endl;
}