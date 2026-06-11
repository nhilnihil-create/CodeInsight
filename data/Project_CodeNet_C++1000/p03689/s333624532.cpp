#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<62;

int main() {
  ll h,w,y,x;
  cin >> h >> w >> y >> x;
  if(h%y==0&&w%x==0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  if(w%x) {
    vec s(w+1);
    for(ll i=w;i>=0;i--) {
      if(w-i<x) {
        s[i]=1;
      }
      else {
        s[i]=s[i+x]+1;
      }
    }
    s[0]=0;
    for(ll i=x;i<w;i+=x) {
      s[i]=s[i-x]-1;
    }
    vec a(w);
    for(ll i=0;i<w;i++) {
      a[i]=s[i+1]-s[i];
    }
    for(ll i=0;i<h;i++) {
      for(ll j=0;j<w;j++) {
        if(j) cout << " ";
        cout << a[j];
      }
      cout << endl;
    }
  }
  else {
    vec s(h+1);
    for(ll i=h;i>=0;i--) {
      if(h-i<y) {
        s[i]=1;
      }
      else {
        s[i]=s[i+y]+1;
      }
    }
    s[0]=0;
    for(ll i=y;i<h;i+=y) {
      s[i]=s[i-y]-1;
    }
    vec a(h);
    for(ll i=0;i<h;i++) {
      a[i]=s[i+1]-s[i];
    }
    for(ll i=0;i<h;i++) {
      for(ll j=0;j<w;j++) {
        if(j) cout << " ";
        cout << a[i];
      }
      cout << endl;
    }
  }
}