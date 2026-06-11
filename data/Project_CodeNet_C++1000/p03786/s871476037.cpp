#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;++i){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  vector<ll> s(n+1,0);
  for(int i=0;i<n;++i){
    s[i+1]=s[i]+a[i];
  }
  ll ans=n;
  for(int i=1;i<n;++i){
    if(s[i]*2<a[i]) ans=min(ans,n-i);
  }
  cout << ans << endl;
  return 0;
}
