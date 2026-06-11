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
  vec s(n);
  for(ll i=0;i<n;i++) cin >> s[i];
  sort(s.begin(),s.end());
  ll ans=0;
  for(ll i=0;i<n;i++) {
    ans+=s[i];
  }
  for(ll i=0;i<n;i++) {
    if(ans%10==0&&s[i]%10) {
      ans-=s[i];
    }
  }
  if(ans%10) cout << ans << endl;
  else cout << 0 << endl;
}