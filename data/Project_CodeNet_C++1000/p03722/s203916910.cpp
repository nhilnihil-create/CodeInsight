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
  ll n,m;
  cin >> n >> m;
  vec a(m),b(m),c(m);
  for(ll i=0;i<m;i++) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--,b[i]--;
  }
  vec d(n,-inf);
  d[0]=0;
  for(ll i=0;i<m;i++) {
    for(ll j=0;j<m;j++) {
      d[b[j]]=max(d[b[j]],d[a[j]]+c[j]);
    }
  }
  ll ans=d[n-1];
  for(ll i=0;i<m;i++) {
    for(ll j=0;j<m;j++) {
      d[b[j]]=max(d[b[j]],d[a[j]]+c[j]);
    }
  }
  if(ans!=d[n-1]) {
    cout << "inf " << endl;
  }
  else {
    cout << ans << endl;
  }
}