#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std; typedef long long ll; const int INF=1e9; typedef pair<ll,ll> P;

int main() {
  ll k; cin>>k;
  ll n=50;
  ll a[n]; fill(a,a+n,k/n);
  for(int i=n-1,j=1;i>=0;i--,j++) {
    if (j<=k%n) a[i]+=n;
    else a[i]+=n-(k%n+1);
  }
  cout<<n<<endl;
  for(int i=0;i<n;i++) {
    cout<<a[i]<<" ";
  }
}