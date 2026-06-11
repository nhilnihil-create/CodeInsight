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
  ll n,k,x,y;
  cin >> n >> k >> x >> y;
  ll ans=0;
  if(n<=k) {
    ans+=n*x;
  }
  else {
    ans+=k*x;
    ans+=(n-k)*y;
  }
  cout << ans << endl;
}