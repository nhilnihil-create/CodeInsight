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
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  ll sum=0;
  ll ans=1;
  for(ll i=0;i<n-1;i++) {
    sum+=a[i];
    if(2*sum>=a[i+1]) {
      ans++;
    }
    else {
      ans=1;
    }
  }
  cout << ans << endl;
}