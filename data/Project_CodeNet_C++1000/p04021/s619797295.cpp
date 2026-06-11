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
  vec a(n);
  vec s(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
    s[i]=a[i];
  }
  sort(s.begin(),s.end());
  map<ll,ll> change;
  for(ll i=0;i<n;i++) {
    change[s[i]]=i%2;
  }
  ll ans=0;
  for(ll i=0;i<n;i+=2) {
    ans+=change[a[i]];
  }
  cout << ans << endl;
}