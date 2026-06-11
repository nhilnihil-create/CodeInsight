#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

//nCk 繰り返し高速
ll comb1(ll n, ll k) {
  ll res=1;
  if(n-k<k) {
    k=n-k;
  }
  ll k1=k;
  set<ll> al;
  for(ll i=n;i>=n-k+1;i--) {
    res=res*i;
    for(ll j=2;j<=k;j++) {
      if(al.count(j)) continue;
      if(res%j==0) {
        res/=j;
        al.insert(j);
      }
    }
  }
  return res;
}

int main() {
  ll n,a,b;
  cin >> n >> a >> b;
  vec v(n);
  map<ll,ll> count;
  for(ll i=0;i<n;i++) {
    cin >> v[i];
    count[v[i]]++;
  }
  sort(v.rbegin(),v.rend());
  double sum=0;
  for(ll i=0;i<a;i++) {
    sum+=v[i]/double(a);
  }
  cout << fixed << setprecision(10) << sum << endl;
  ll ans=0;
  if(v[a-1]==v[0]) {
    for(ll i=a;i<=min(b,count[v[0]]);i++) {
      ans+=comb1(count[v[0]],i);
    }
  }
  else {
    ll temp=0;
    for(ll i=0;i<a;i++) {
      if(v[i]!=v[a-1]) temp++;
    }
    ans=comb1(count[v[a-1]],a-temp);
  }
  cout << ans << endl;
}