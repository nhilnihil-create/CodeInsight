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
  ll q,h,s,d;
  cin >> q >> h >> s >> d;
  ll n;
  cin >> n;
  q*=4;
  h*=2;
  s=min({q,h,s});
  d=min(d,s*2);
  ll ans=n/2*d+n%2*s;
  cout << ans << endl;
}