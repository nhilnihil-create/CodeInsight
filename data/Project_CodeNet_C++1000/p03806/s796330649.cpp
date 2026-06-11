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
  ll n,ma,mb;
  cin >> n >> ma >> mb;
  vec a(n);
  vec b(n);
  vec c(n);
  for(ll i=0;i<n;i++) cin >> a[i] >> b[i] >> c[i];
  mat dp(401,vec(401,inf));
  dp[0][0]=0;
  for(ll i=0;i<n;i++) {
    for(ll j=400;j>-1;j--) {
      for(ll k=400;k>-1;k--) {
        if(j-a[i]>-1&&k-b[i]>-1) {
          dp[j][k]=min(dp[j][k],dp[j-a[i]][k-b[i]]+c[i]);
        }
      }
    }
  }
  ll ans=inf;
  for(ll i=1;ma*i<401&&mb*i<401;i++) {
    ans=min(ans,dp[ma*i][mb*i]);
  }
  if(ans==inf) {
    ans=-1;
  }
  cout << ans << endl;
}