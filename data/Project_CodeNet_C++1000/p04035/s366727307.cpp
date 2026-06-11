#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
const ll inf=1e18;

int main() {
  ll n,l;
  cin >> n >> l;
  vec a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  ll pos=-1;
  for(ll i=0;i<n-1;i++) {
    if(a[i]+a[i+1]>=l) {
      pos=i;
    }
  }
  if(pos==-1) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  for(ll i=0;i<pos;i++) {
    cout << i+1 << endl;
  }
  for(ll j=n-2;j>pos;j--) {
    cout << j+1 << endl;
  }
  cout << pos+1 << endl;
}