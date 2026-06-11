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
  ll n;
  cin >> n;
  vector<pll> a(n+1);
  for(ll i=0;i<n;i++) cin >> a[i].first,a[i].second=i;
  vec ans(n);
  sort(a.rbegin(),a.rend());
  ll id=inf;
  for(ll i=0;i<n;i++) {
    id=min(id,a[i].second);
    ans[id]+=(i+1)*(a[i].first-a[i+1].first);
  }
  for(ll i=0;i<n;i++) {
    cout << ans[i] << endl;
  }
}