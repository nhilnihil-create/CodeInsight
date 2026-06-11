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
  ll n,k;
  cin >> n >> k;
  ll ans=k;
  for(ll i=1;i<n;i++) {
    ans*=(k-1);
  }
  cout << ans << endl;
}