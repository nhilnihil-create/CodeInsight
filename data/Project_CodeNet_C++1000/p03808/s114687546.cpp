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
  vec a(n);
  ll s=0;
  for(ll i=0;i<n;i++) {
    cin >> a[i];
    s+=a[i];
  }
  ll cnt=0;
  ll d=n*(n+1)/2;
  if(s%d) {
    cout << "NO" << endl;
    return 0;
  }
  else {
    cnt=s/d;
  }
  vec b(n);
  for(ll i=0;i<n;i++) {
    b[(i+1)%n]=a[(i+1)%n]-a[i];
  }
  for(ll i=0;i<n;i++) {
    b[i]-=cnt;
  }
  ll f=0;
  for(ll i=0;i<n;i++) {
    if(b[i]%n||b[i]>0) {
      cout << "NO" << endl;
      return 0;
    }
    f-=b[i]/n;
  }
  if(f==cnt) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}