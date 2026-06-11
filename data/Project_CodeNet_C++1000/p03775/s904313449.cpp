#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n; cin>>n;
  int ans=100;
  for(ll i=1;i<=sqrt(n);i++) {
    if(n%i==0) {
      int len_a=to_string(i).size();
      int len_b=to_string(n/i).size();
      int f=max(len_a,len_b);
      ans=min(ans,f);
    }
  }
  cout<<ans<<endl;
}
