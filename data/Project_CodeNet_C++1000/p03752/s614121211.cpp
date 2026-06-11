#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  ll ans=1e18;
  for(ll i=0;i<(1<<n);i++) {
    bitset<15> b(i);
    vector<ll> aa(n);
    ll tans=0;
    ll temp=a[0];
    for(ll j=0;j<n;j++) {
      if(j!=0&&b.test(j)) {
        aa[j]=max(a[j],temp+1);
        tans+=aa[j]-a[j];
      }
      else {
        aa[j]=a[j];
      }
      temp=max(temp,aa[j]);
    }
    ll count=0;
    temp=0;
    for(ll j=0;j<n;j++) {
      if(temp<aa[j]) {
        count++;
      }
      temp=max(temp,aa[j]);
    }
    if(count>=k) {
      ans=min(ans,tans);
    }
  }
  cout << ans << endl;
}