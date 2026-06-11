#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n,c,k;
  cin >> n >> c >> k;
  ll ans=0;
  ll cnt=0;
  ll ti=-inf;
  vec t(n);
  for(ll i=0;i<n;i++) cin >> t[i];
  sort(t.begin(),t.end());
  for(ll i=0;i<n;i++) {
    if(ti+k<t[i]||c<=cnt) {
      cnt=1;
      ti=t[i];
      ans++;
    }
    else {
      cnt++;
    }
  }
  cout << ans << endl;
}