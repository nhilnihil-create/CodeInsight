#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

vec tfact(1e7+1);
void fact(ll n) {
  for(ll i=0;i<=n;i++) {
    if(i==0) {
      tfact[i]=1;
    }
    else {
      tfact[i]=tfact[i-1]*i%mod;
    }
  }
}

int main() {
  ll n;
  cin >> n;
  fact(n);
  vec x(n);
  for(ll i=0;i<n;i++) cin >> x[i];
  stack<ll> q;
  ll ans=1;
  for(ll i=0;i<n;i++) {
    q.push(x[i]);
    ll k=q.size();
    if(x[i]<2*k-1) {
      (ans*=k)%=mod;
      q.pop();
    }
  }
  (ans*=tfact[q.size()])%=mod;
  cout << ans << endl;
}