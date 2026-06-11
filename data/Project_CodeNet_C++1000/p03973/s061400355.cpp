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
  ll temp=1;
  ll ans=0;
  for(ll i=0;i<n;i++) {
    if(a[i]<temp) continue;
    if(a[i]==temp) {
      temp++;
      continue;
    }
    ans+=(a[i]-1)/temp;
    if(temp==1) temp++;
  }
  cout << ans << endl;
}