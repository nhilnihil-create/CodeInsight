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
  vec x(n);
  map<ll,ll> cntm;
  map<ll,ll> cnt;
  for(ll i=0;i<n;i++) cin >> x[i];
  for(ll i=0;i<n;i++) cntm[x[i]%m]++,cnt[x[i]]++;
  ll ans=0;
  for(ll i=0;i<m;i++) {
    ll tmp=min(cntm[i],cntm[(m-i)%m]);
    if(i==(m-i)%m) {
      tmp/=2;
      ans+=tmp;
      cntm[i]-=tmp*2;
    }
    else {
      ans+=tmp;
      cntm[i]-=tmp;
      cntm[m-i]-=tmp;
    }
  }
  for(ll i=0;i<n;i++) {
    ll tmp=min(cnt[x[i]]/2,cntm[x[i]%m]/2);
    ans+=tmp;
    cnt[x[i]]-=tmp*2;
    cntm[x[i]%m]-=tmp*2;
  }
  cout << ans << endl;
}