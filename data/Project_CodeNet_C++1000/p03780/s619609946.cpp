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
  ll n,k;
  cin >> n >> k;
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  ll l=-1,r=n;
  while(l+1<r) {
    ll tmp=(l+r)>>1;
    mat dp(n+1,vec(k,0));
    dp[0][0]=1;
    for(ll i=0;i<n;i++) {
      for(ll j=0;j<k;j++) {
        dp[i+1][j]|=dp[i][j];
        if(i!=tmp&&j+a[i]<k) {
          dp[i+1][j+a[i]]|=dp[i][j];
        }
      }
    }
    ll f=0;
    for(ll i=max(k-a[tmp],0LL);i<k;i++) {
      f|=dp[n][i];
    }
    if(f) {
      r=tmp;
    }
    else {
      l=tmp;
    }
  }
  cout << l+1 << endl;
}