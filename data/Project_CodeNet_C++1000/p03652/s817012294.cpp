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
  ll n,m;
  cin >> n >> m;
  mat a(n,vec(m));
  for(ll i=0;i<n;i++) for(ll j=0;j<m;j++) cin >> a[i][j];
  vec num(n);
  set<ll> check;
  ll ans=inf;
  for(ll i=0;i<m;i++) {
    map<ll,ll> cnt;
    for(ll j=0;j<n;j++) {
      while(check.count(a[j][num[j]])) {
        num[j]++;
      }
      cnt[a[j][num[j]]]++;
    }
    ll tans=0,id;
    for(ll j=1;j<=m;j++) {
      if(tans<cnt[j]) {
        tans=cnt[j];
        id=j;
      }
    }
    check.insert(id);
    ans=min(tans,ans);
  }
  cout << ans << endl;
}