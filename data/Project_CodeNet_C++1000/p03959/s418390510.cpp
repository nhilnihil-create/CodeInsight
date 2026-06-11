#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n;
  cin >> n;
  vec t(n+1);
  vec a(n+1);
  for(ll i=0;i<n;i++) {
    cin >> t[i+1];
  }
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  ll ans=1;
  for(ll i=0;i<n;i++) {
    if(t[i]==t[i+1]&&a[i]==a[i+1]) {
      (ans*=min(t[i+1],a[i]))%=mod;
    }
    else {
      if(t[i]!=t[i+1]&&a[i]!=a[i+1]) {
        if(t[i+1]!=a[i]) {
          ans=0;
        }
      }
      else if(t[i]!=t[i+1]&&t[i+1]>a[i]) {
        ans=0;
      }
      else if(a[i]!=a[i+1]&&a[i]>t[i+1]) {
        ans=0;
      }
    }
  }
  cout << ans << endl;
}