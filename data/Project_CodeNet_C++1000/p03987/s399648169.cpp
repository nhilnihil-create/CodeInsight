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
  vec a(n+1);
  for(ll i=1;i<=n;i++) {
    ll tmp;
    cin >> tmp;
    a[tmp]=i;
  }
  set<ll> al;
  al.insert(0);
  al.insert(n+1);
  ll ans=0;
  for(ll i=1;i<=n;i++) {
    auto it=al.upper_bound(a[i]);
    ans+=i*(*it-a[i])*(a[i]-*--it);
    al.insert(a[i]);
  }
  cout << ans << endl;
}