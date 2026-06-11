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
  ll n;
  cin >> n;
  vec a(n);
  ll mx=0;
  ll mn=inf; 
  for(ll i=0;i<n;i++) {
    cin >> a[i];
    mx=max(mx,a[i]);
    mn=min(mn,a[i]);
  }
  if(mx-mn>1) {
    cout << "No" << endl;
  }
  else if(mx==mn) {
    if(mx+1==n||mx*2<=n) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else {
    ll x=0;
    ll y=0;
    for(ll i=0;i<n;i++) {
      if(a[i]==mx) x++;
      if(a[i]==mn) y++;
    }
    if(y<mx&&(mx-y)*2<=x) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}