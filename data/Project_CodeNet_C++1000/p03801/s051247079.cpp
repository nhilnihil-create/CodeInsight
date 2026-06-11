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
  for(ll i=1;i<=n;i++) {
    cin >> a[i].first;
    a[i].second=i;
  }
  sort(a.begin(),a.end());
  ll mn=inf;
  vec ans(n+1);
  for(ll i=n;i;i--) {
    mn=min(mn,a[i].second);
    ans[mn]+=abs(a[i].first-a[i-1].first)*(n-i+1);
  }
  for(ll i=1;i<=n;i++) cout << ans[i] << endl;
}