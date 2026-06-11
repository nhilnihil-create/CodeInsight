#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std; typedef long long ll; const int INF=1e9; typedef pair<ll,ll> P;

int main() {
  int n; cin>>n;
  ll a[n]; for(int i=0;i<n;i++) cin>>a[i];
  ll b[n]; b[0]=a[0]; for(int i=1;i<n;i++) b[i]=b[i-1]+a[i];
  ll c[n]; c[n-1]=a[n-1]; for(int i=n-2;i>=0;i--) c[i]=c[i+1]+a[i];

  //for(ll x:b) cout<<x<<" "; cout<<endl;
  //for(ll x:c) cout<<x<<" "; cout<<endl;

  ll an=1e18;
  for(int i=1;i<=n-1;i++) {
    an=min(an, abs(b[i-1]-c[i]));
  }
  cout<<an<<endl;
}