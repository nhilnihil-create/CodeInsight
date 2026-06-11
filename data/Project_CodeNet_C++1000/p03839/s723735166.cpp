#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e15;
 
int main() {
  ll n,k;
  cin >> n >> k;
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  vec s(n);
  s[0]=a[0];
  for(ll i=0;i<n-1;i++) {
    s[i+1]=s[i]+a[i+1];
  }
  vec p(n);
  p[0]=max(a[0],0LL);
  for(ll i=0;i<n-1;i++) {
    p[i+1]=p[i]+max(a[i+1],0LL);
  }
  ll ans=-inf;
  for(ll i=0;i+k-1<n;i++) {
    ll tmp=0;
    tmp+=s[i+k-1];
    if(i) tmp-=s[i-1];
    tmp=max(tmp,0LL);
    if(i) tmp+=p[i-1];
    if(i+k<n) tmp+=p[n-1]-p[i+k-1];
    ans=max(ans,tmp);
  }
  cout << ans << endl;
}