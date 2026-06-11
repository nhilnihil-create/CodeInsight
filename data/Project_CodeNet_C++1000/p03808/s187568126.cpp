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
  ll sum=0;
  for(ll i=0;i<n;i++) {
    cin >> a[i];
    sum+=a[i];
  }
  if(sum%(n*(n+1)/2)) {
    cout << "NO" << endl;
    return 0;
  }
  ll cnt=sum/(n*(n+1)/2);
  vec d(n);
  for(ll i=0;i<n;i++) {
    d[i]=a[(i+1)%n]-a[i];
    d[i]-=cnt;
  }
  ll f=1;
  for(ll i=0;i<n;i++) {
    if(d[i]>0||d[i]%n) f=0;
  }
  if(f) cout << "YES" << endl;
  else cout << "NO" << endl;
}