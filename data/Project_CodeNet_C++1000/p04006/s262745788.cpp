#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
#include <set>
using namespace std; typedef long long ll; const int MINF=-1e9; typedef pair<int,int> P;

int main() {
  ll n,x; cin>>n>>x;
  ll a[n]; for(int i=0;i<n;i++) cin>>a[i];
  if (n==1) {
    cout<<a[0]<<endl; return 0;
  }
  ll an=1e18;
  ll b[n];for(int i=0;i<n;i++) b[i]=a[i];
  for(ll i=0;i<=n;i++) {
    ll sm=0;
    for(int j=0;j<n;j++) {
      sm+=b[j];
    }
    an=min(an,sm+x*i);
    //cout<<i<<" "<<an<<endl;
    if (i==n) break;

    ll temp0=min(b[0],b[n-1]);
    for(int j=n-1;j>=1;j--) {
      b[j]=min(b[j-1],b[j]);
    }
    b[0]=temp0;
    //for(int j=0;j<n;j++) cout<<b[j]<<" "; cout<<endl;
  }
  cout<<an<<endl;
}