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
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  ll mx=a[n-1];
  vec cnt(mx+1);
  for(ll i=0;i<n;i++) {
    cnt[a[i]]++;
  }
  ll f=1;
  for(ll i=0;i<=mx;i++) {
    if(cnt[i]&&i<mx/2) f=0;
    if(mx%2&&i==(mx+1)/2&&cnt[i]!=2) f=0;
    if(mx%2==0&&i==mx/2&&cnt[i]!=1) f=0;
    if(i>mx/2&&!cnt[i]) f=0;
  }
  if(f) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}