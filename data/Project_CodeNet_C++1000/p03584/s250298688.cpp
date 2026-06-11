#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;

int main() {
  ll n,k;
  cin >> n >> k;
  vec a(n);
  vec b(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i] >> b[i];
  }
  ll ans=0;
  for(ll i=0;i<n;i++) {
    if((a[i]|k)==k) ans+=b[i];
  }
  for(ll i=0;i<=30;i++) {
    if(k&(1<<i)) {
      ll mask=((k>>(i+1))<<(i+1))+(1<<i)-1;
      ll sum=0;
      for(ll j=0;j<n;j++) {
        if((a[j]|mask)==mask) sum+=b[j];
      }
      ans=max(ans,sum);
    }
  }
  cout << ans << endl;
}