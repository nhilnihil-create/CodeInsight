#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

typedef pair<pll,pll> dpll;

int main() {
  ll n;
  cin >> n;
  vec a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
    a[i]--;
  }
  ll ans=0;
  for(ll i=0;i<n;i++) ans+=i==a[a[i]];
  cout << ans/2 << endl;
}