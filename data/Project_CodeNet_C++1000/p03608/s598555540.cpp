#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e15;

ll n,m,R;
vec r(10);
mat d(210,vec(210,inf));


int main() {
  cin >> n >> m >> R;
  for(ll i=0;i<R;i++) {
    cin >> r[i];
    r[i]--;
  }
  for(ll i=0;i<n;i++) d[i][i]=0;
  for(ll i=0;i<m;i++) {
    ll a,b,c;
    cin >> a >> b >> c;
    a--,b--;
    d[a][b]=d[b][a]=c;
  }
  for(ll k=0;k<n;k++) {
    for(ll i=0;i<n;i++) {
      for(ll j=0;j<n;j++) {
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  vec p(R);
  for(ll i=0;i<R;i++) {
    p[i]=i;
  }
  ll ans=inf;
  while(1) {
    ll tmp=0;
    for(ll i=0;i<R-1;i++) {
      tmp+=d[r[p[i]]][r[p[i+1]]];
    }
    ans=min(ans,tmp);
    if(!next_permutation(p.begin(),p.end())) break;
  }
  cout << ans << endl;
}