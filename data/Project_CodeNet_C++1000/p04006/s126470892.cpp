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
  ll n,x;
  cin >> n >> x;
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  vec b(n,inf);
  ll ans=inf;
  for(ll i=0;i<n;i++) {
    ll tans=0;
    for(ll j=0;j<n;j++) {
      b[j]=min(b[j],a[(j-i+n)%n]);
      tans+=b[j];
    }
    tans+=i*x;
    ans=min(ans,tans);
  }
  cout << ans << endl;
}