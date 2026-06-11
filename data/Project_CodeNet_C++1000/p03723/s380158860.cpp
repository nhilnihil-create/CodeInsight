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
  ll a,b,c;
  cin >> a >> b >> c;
  ll cnt=0;
  while(1) {
    if(a%2||b%2||c%2) break;
    ll na=b/2+c/2;
    ll nb=a/2+c/2;
    ll nc=a/2+b/2;
    a=na;
    b=nb;
    c=nc;
    cnt++;
    if(cnt>1e6) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << cnt << endl;
}