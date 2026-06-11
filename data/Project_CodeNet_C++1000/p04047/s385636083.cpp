#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const int INF = 1000000;
const double PI=3.14159265359;

int main(){

  ll n;cin>>n;
  ll l[2*n];rep(i,0,2*n)cin>>l[i];
  sort(l,l+2*n);
  // reverse(l,l+2*n);
  ll ans=0;
  rep(i,0,n)ans+=l[2*i];

  out(ans);




  return 0;
}
