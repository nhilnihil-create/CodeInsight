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
  ll n,m;
  cin >> n >> m;
  mat d(n,vec(n,inf));
  vec a(m),b(m),c(m);
  for(ll i=0;i<n;i++) d[i][i]=0;
  for(ll i=0;i<m;i++) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--,b[i]--;
    d[a[i]][b[i]]=c[i];
    d[b[i]][a[i]]=c[i];
  }
  for(ll k=0;k<n;k++) {
    for(ll i=0;i<n;i++) {
      for(ll j=0;j<n;j++) {
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  ll ans=0;
  for(ll i=0;i<m;i++) {
    ans+=d[a[i]][b[i]]!=c[i];
  }
  cout << ans << endl;
}